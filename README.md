#  Library Tracker System

A full-stack Library Management System developed using **Next.js (Frontend)** and **C++ (Backend)**. The project enables efficient library management through book tracking, borrowing, returning, searching, sorting, and statistics, while providing separate interfaces for administrators and users.

---

##  Features

###  Admin Features
- Add New Books
- Edit Book Details
- Delete Books
- View Library Statistics
- Save Library Data
- Admin Login Authentication

###  User Features
- Display All Books
- Display Available Books
- Display Borrowed Books
- Borrow Books
- Return Books
- Search Books
- Sort Books

###  Search
- Search by Title
- Search by Author
- Search by Category
- Search by Book ID
- Case-Insensitive Search

###  Library Management
- Borrow & Return Books
- Issue Date Tracking
- Return Date Tracking
- Fine Calculation
- Book Availability Status
- Borrow Count Tracking
- Library Statistics

###  Data Management
- File-Based Data Storage
- Save & Load Books
- Persistent Library Records

---

# Tech Stack

## Frontend
- Next.js
- React
- TypeScript
- Tailwind CSS

## Backend
- C++
- Object-Oriented Programming (OOP)
- File Handling (Text Files)
- Standard Template Library (STL)

---

# Project Structure

```
Library-Tracker-System
│
├── frontend
│   ├── app
│   ├── components
│   ├── public
│   └── package.json
│
├── backend
│   ├── include
│   ├── src
│   ├── data
│   └── LibraryTracker.exe
│
└── README.md
```

---

# Installation

## Clone Repository

```bash
git clone https://github.com/jasmine123jass/Library-Tracker-System.git
```

---

## Frontend

```bash
cd frontend
npm install
npm run dev
```

---

## Backend

```bash
cd backend

g++ src/Book.cpp \
src/FileManager.cpp \
src/Library.cpp \
src/UI.cpp \
src/main.cpp \
-Iinclude \
-o LibraryTracker

./LibraryTracker
```

---

# Usage

### Administrator
- Login using Admin credentials
- Add, Edit and Delete books
- View statistics
- Save records

### User
- Browse books
- Search books
- Borrow books
- Return books
- View available books
- View borrowed books

---

# Key Functionalities

- CRUD Operations
- File Handling
- Role-Based Access
- Search & Sorting
- Fine Management
- Issue & Return Tracking
- Statistics Dashboard
- Object-Oriented Design

---

# Object-Oriented Concepts Used

- Classes & Objects
- Encapsulation
- Constructors
- Member Functions
- File Handling
- STL Vectors
- Algorithms

---

# Future Enhancements

- SQLite/MySQL Database
- REST API Integration
- JWT Authentication
- QR Code Support
- Email Notifications
- Multi-User Login
- Dashboard Analytics
- Cloud Deployment

---

# Author

**Srujitha Jasmine Baggam**

B.Tech Computer Science (AI & Machine Learning)

Lovely Professional University

GitHub:
https://github.com/jasmine123jass

---

# Project Highlights

- Full Stack Library Management System
- Modern Next.js Frontend
- C++ Object-Oriented Backend
- File-Based Persistent Storage
- Role-Based Authentication
- Professional GitHub Repository
- Placement & Interview Ready

---

## License

This project is created for educational and portfolio purposes.