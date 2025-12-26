function submitFeedback() {
    const name = document.getElementById("name").value;
    const email = document.getElementById("email").value;
    const subject = document.getElementById("subject").value;
    const message = document.getElementById("message").value;

    const data = `name=${name}&email=${email}&subject=${subject}&message=${message}`;

    fetch("http://localhost:8080", {
        method: "POST",
        headers: {
            "Content-Type": "text/plain"
        },
        body: data
    })
    .then(response => response.text())
    .then(result => {
        alert(result);
    })
    .catch(error => {
        alert("Server not running!");
    });
}
