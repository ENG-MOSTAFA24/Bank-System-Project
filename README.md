# 🏦 Bank Management System (C++ / OOP)

A console-based **Bank Management System** built entirely from scratch in **C++**, designed as a practical, hands-on application of **Object-Oriented Programming (OOP)** principles. The system simulates a real banking application: user authentication, client management, financial transactions, user/permission management, currency exchange, and activity logging — all persisted to flat files.

This project was built to solidify and demonstrate core OOP concepts through a real, non-trivial application rather than isolated examples.

---

## ✨ Key Features

- 🔐 **Login System** with file-based user validation and a 3-attempt lockout policy.
- 👤 **Client Management** — Add, Delete, Update, Find, and List all clients.
- 💰 **Transactions Module** — Deposit, Withdraw, Transfer, Transfer Log, and Total Balances.
- 🛡️ **User Management** — Add, Delete, Update, Find, and List system users with **permission-based access control** using bitwise/binary flags.
- 📜 **Login Register** — Full audit log of every login attempt on the system.
- 💱 **Currency Exchange** — Convert between world currencies using live exchange logic.
- 🚪 **Logout** — Returns to the login screen without closing the program.
- 💾 **Persistent Storage** — All data (clients, users, login history, transfer logs) is read from and written to `.txt` files, so data survives between runs.

---

## 🧠 OOP Concepts Applied

This project was built specifically to apply and reinforce the four pillars of OOP, plus good software design practices:

| Concept | How it's used |
|---|---|
| **Encapsulation** | Client and User data (account number, balance, PIN, permissions, etc.) is kept private inside classes and accessed only through getters/setters and controlled methods. |
| **Inheritance** | Every screen in the system is modeled as its own class, and shared behavior (reading/writing files, printing UI, navigation) is placed in base classes that each screen class inherits from. |
| **Polymorphism** | Common screen operations (e.g., `showScreen()`, `execute()`) are overridden per screen class, allowing each screen to define its own behavior while being handled through a shared interface. |
| **Constructors** | Used extensively to initialize `Client`, `User`, and `Screen`-based objects safely and consistently, avoiding manual/duplicate setup code. |
| **Abstraction** | Complex file I/O and validation logic is hidden behind simple class methods, so the main program logic stays clean and readable. |
| **Divide and Conquer (Separation of Concerns)** | Each menu/screen (Add Client, Delete Client, Transactions, Manage Users, etc.) is isolated into its own class, making the code modular, testable, and easy to extend. |

---

## 🖥️ System Flow

### 1. Login Screen
- The program starts with a login prompt.
- Credentials are validated against `Users.txt`.
- The user gets **3 attempts**; after 3 failed attempts, the program **shuts down** for security.
- On success, the user is taken to the **Main Menu** — but only the options their permissions allow are accessible.

### 2. Main Menu
```
1. Show Client List
2. Add New Client
3. Delete Client
4. Update Client Info
5. Find Client
6. Transactions
7. Manage Users
8. Login Register
9. Currency Exchange
10. Logout
```

---

## 📋 Screens in Detail

### 🧾 1. Show Client List
Reads all client records from `Clients.txt` and displays them in a formatted table showing: **Account Number, Name, Phone, Email, PIN Code, Balance**.

### ➕ 2. Add New Client
- Prompts for an **Account Number**.
- Checks `Clients.txt` for a duplicate — if it exists, the user is looped back until a **unique** account number is entered.
- Collects the remaining client details and appends the new record to `Clients.txt`.

### ➖ 3. Delete Client
- Prompts for an Account Number.
- If not found, keeps asking until a valid/existing account number is entered.
- Displays the client's full card/details.
- Asks for **confirmation** before permanently deleting the record from `Clients.txt`.

### ✏️ 4. Update Client Info
- Finds the client by Account Number and allows editing any of their stored information, then saves the changes back to the file.

### 🔍 5. Find Client
- Looks up a client by Account Number and prints their full card if found.

### 💵 6. Transactions
- **Deposit** — Adds funds to a client's balance.
- **Withdraw** — Subtracts funds, with validation to **block withdrawal** if the amount exceeds the available balance.
- **Transfer** — Moves funds between two client accounts, with the same balance validation as Withdraw.
- **Transfer Log** — Every transfer is recorded with date, sender, and receiver in a dedicated log file.
- **Total Balances** — Displays the combined balance across all clients in the bank.

### 👥 7. Manage Users
- **List Users** — Displays all system users with their names, emails, and permissions.
- **Add New User** — Creates a new user and assigns permissions using **binary/bitwise flags**, controlling exactly which screens they can access.
- **Delete User** — Removes a user, with a safeguard that **prevents deleting the Admin account**.
- **Update User** — Edits a user's data/permissions, with a safeguard that **prevents modifying the Admin's data or permissions**.
- **Find User** — Displays a specific user's card if found.

### 🕘 8. Login Register
Every login attempt (successful or not) made on the system is logged with details to a dedicated file, creating a full audit trail.

### 💱 9. Currency Exchange
Supports conversion between a wide range of world currencies based on exchange rates.

### 🚪 10. Logout
Ends the current session and returns to the Login Screen without terminating the application.

---

## 🗂️ Data Files

| File | Purpose |
|---|---|
| `Users.txt` | Stores system users, credentials, and their permission flags. |
| `Clients.txt` | Stores all bank client records (Account Number, Name, Phone, Email, PIN, Balance). |
| `TransferLog.txt` | Stores a history of all transfer transactions. |
| `LoginRegister.txt` | Stores a history of all login attempts. |



---

## 🧱 Project Architecture

The project follows a **"Divide and Conquer"** design: instead of one large monolithic file, each screen/feature is its own class, inheriting shared functionality from base classes. This keeps the code:

- **Modular** — each screen can be modified independently.
- **Reusable** — shared logic (file handling, printing headers, input validation) lives in base classes.
- **Extensible** — new screens/features can be added by creating a new class that inherits from the base screen structure.
---

## 🚀 Future Improvements

- Migrate from flat `.txt` files to a proper database (SQLite/MySQL).
- Add password hashing instead of plain-text storage.
- Build a GUI version using Qt or a web-based frontend.
- Add unit tests for core banking logic.

---

## 👨‍💻 About This Project

This project was built entirely from scratch as a self-driven exercise to practice and apply Object-Oriented Programming concepts in C++, including **encapsulation, inheritance, polymorphism, constructors, and abstraction**, through a realistic, multi-feature application rather than isolated exercises.

---

## 📄 License

This project is open for learning purposes. Feel free to fork, explore, and build on top of it.
