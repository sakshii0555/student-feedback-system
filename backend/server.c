#include <stdio.h>
#include <winsock2.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define PORT 8080

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;
    char buffer[8192];

    WSAStartup(MAKEWORD(2,2), &wsa);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server, sizeof(server));
    listen(server_socket, 3);

    printf("Server running at http://localhost:%d\n", PORT);

    c = sizeof(struct sockaddr_in);

    while ((client_socket = accept(server_socket, (struct sockaddr *)&client, &c)) != INVALID_SOCKET) {

        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);

        // CASE 1: Browser opened localhost → serve UI
        if (strstr(buffer, "GET / ") != NULL) {

            FILE *fp = fopen("index.html", "r");
            char html[8192] = {0};
            fread(html, 1, sizeof(html), fp);
            fclose(fp);

            char response[9000];
            sprintf(response,
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n\r\n"
                "%s", html);

            send(client_socket, response, strlen(response), 0);
        }

        // CASE 2: Form submitted → save feedback
        else if (strstr(buffer, "POST") != NULL) {

            char *data = strstr(buffer, "\r\n\r\n");
            if (data) {
                data += 4;
                FILE *fp = fopen("feedback.txt", "a");
                fprintf(fp, "%s\n", data);
                fclose(fp);
            }

            char response[] =
                "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/plain\r\n\r\n"
                "Feedback submitted successfully!";

            send(client_socket, response, strlen(response), 0);
        }

        closesocket(client_socket);
    }

    WSACleanup();
    return 0;
}

