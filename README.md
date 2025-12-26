# 🎓 Student Feedback System  
### C Language | API-Based Full Stack Project

The **Student Feedback System** is a full-stack academic project developed using **C language** for the backend and **HTML, CSS, and JavaScript** for the frontend. The project demonstrates **client–server communication using HTTP APIs** without using JSON, databases, or external server software such as XAMPP.  

The backend server is implemented using **Windows Winsock** and runs locally through the **command line**, while the frontend provides a **clean, responsive, and user-friendly feedback form interface**.

---

## 📝 Project Description

This system allows students to submit feedback through a web-based form. The submitted data is sent to a **C-based backend server via HTTP POST requests** and is stored locally using **file handling techniques** in plain text format. The project focuses on understanding **API integration, socket programming, and full-stack workflow using C language**.

---

## 🛠️ Technologies Used

- **Frontend:** HTML, CSS, JavaScript  
- **Backend:** C Language (Windows Winsock)  
- **Communication Protocol:** HTTP API  
- **Platform:** Windows  

---

## 📂 Project Structure
student-feedback-system-c/
│
├── frontend/
│ ├── index.html – Feedback form user interface
│ ├── style.css – Styling, layout, and design
│ └── script.js – API communication logic
│
└── backend/
└── server.c – C backend server using Winsock

▶️ How to Run the Project (Windows – Easy Steps)

1. Open Command Prompt and navigate to the backend folder.
2. 
3. Compile the backend server using GCC:
   gcc server.c -o server -lws2_32
   
4. Run the server:
   server
   
5. The server will start running at:
   http://localhost:8080  
   
6. Open the frontend by double-clicking:
   frontend/index.html

7. Fill in the feedback form and click Submit.  
   The feedback will be sent to the C backend server and stored locally.

## ⭐ Key Features

- API-based frontend and backend integration  
- Backend implemented purely in **C language**  
- Plain text data transfer (**no JSON used**)  
- File-based data storage system  
- Runs without **XAMPP** or any database  
- Easy to understand and implement  
- Suitable for academic mini projects and viva demonstrations  

---

## 🎓 Academic Relevance

This project demonstrates the practical implementation of:
- Socket programming in C  
- HTTP client–server communication  
- File handling in C  
- Full-stack development without frameworks 
