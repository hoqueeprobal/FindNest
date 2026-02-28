# 🏷️ FindNest

**FindNest** is a console-based **Lost and Found Registry System** developed in **C++** while learning **Object-Oriented Programming and Fundamental Algorithms**.  
It allows users to manage lost items by adding, removing, updating, searching, and displaying them **grouped by category**.

---

## 🌟 Features

### 🔹 Core Features
- Add lost items with **unique ID, Name, Category, and Found Location**
- Remove and update items using **Item ID**
- Display all items **grouped and sorted by category**
- Search items by **ID or Name**
- View complete **Audit Log** history of system operations

### 🔹 Utility Features
- Menu-driven console interface
- Prevents duplicate IDs and handles invalid input
- **Merge Sort** used for category-based sorting
- **Linear Search** used for searching items
- Records all **ADD, REMOVE and UPDATE** operations
- Automatically saves **lostfound-data.txt and audit-log.txt**
- Files are saved automatically when the program exits

## 🧩 OOP Concepts Used

### 🔹 Classes & Objects
- `Item` class represents a lost item  
- `LostFoundRegistry` class manages all item operations  

### 🔹 Encapsulation
- Item data members are **private**
- Accessed using **public getter methods**

### 🔹 Abstraction
- Registry class exposes only **essential public methods**
- Internal logic (sorting, searching, validation, audit logging) is hidden

### 🔹 Operator Overloading
- `<` operator is overloaded to compare items by **category**

### 🔹 Modularity
- Program logic is divided into **well-structured functions**
- Improves readability, reusability, and maintenance

---

## 💻 Technologies Used
- **Language:** C++
- **Interface:** Console (Text-based)
- **Data Structures:** Vector
- **Algorithms:** Merge Sort, Linear Search
- **File Handling:** fstream

---

## 📂 Folder Structure
```plaintext
FindNest/
├── screenshots/
├── README.md
├── Project-Documents/
├── findnest.cpp
```
---
## 🚀 How to Run

1. Compile the program:
   ```bash
   g++ findnest.cpp -o FindNest
2. Run the executable:
      ```bash
   ./FindNest

## 📁 Output Files

When the program exits:

**lostfound-data.txt - Contains all items grouped by category**
**audit-log.txt - Contains all ADD, REMOVE, and UPDATE records**
- Files are overwritten each time the program exits
      
## 🎉 Acknowledgments

- Developed while learning and practicing different types of algorithms in C++.  
- Thanks to **Faculty and Team Mates** who helped **review and improve** this project.  
---
