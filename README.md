# 🏷️ FindNest

**FindNest** is a simple **console-based Lost and Found Registry** developed in **C++** while learning **different types of algorithms**.  
It uses **Object-Oriented Programming (OOP) concepts** such as **Classes & Objects, Encapsulation, Abstraction, Operator Overloading and Modularity**.  
The program lets users manage lost items by **adding, removing, and viewing them grouped by category** while practicing **C++ classes, vectors, and algorithms.**

---

## 🌟 Features

### 🔹 Core Features
- Add lost items with **ID, Name, Category, and Found Location**.  
- Remove items by **ID**.  
- Display all items **grouped and sorted by category**.  
- Maintain a **dynamic list of items** using vectors.  

### 🔹 Utility Features
- Menu-driven console interface for easy navigation.  
- Handles invalid inputs gracefully.  
- Merge sort used internally to **sort items by category**.  

---

## 🧩 OOP Concepts Used

**Classes & Objects**  
   - `Item` class represents a lost item with attributes like ID, Name, Category, and Found Location.  
   - `LostFoundRegistry` class manages a collection of items and handles all operations (add, remove, display).

**Encapsulation**  
   - Data members (`id`, `name`, `category`, `foundLocation`) in `Item` are **private**.  
   - Access is controlled using **public getter functions** (`getId()`, `getName()`, etc.).

**Abstraction**  
   - `LostFoundRegistry` exposes only **public methods** like `addItem()`, `removeItem()`, and `displayAll()` while hiding implementation details (like the vector and merge sort).

**Operator Overloading**  
   - The `<` operator is **overloaded** in `Item` to compare items by category for sorting.

**Modularity**  
   - Functions are divided logically into separate methods (adding, removing, displaying, sorting), making the code **organized and reusable**.

---

## 💻 Technologies Used
- **Language:** C++  
- **Compiler:** GCC, MinGW, or any standard C++ compiler  
- **Interface:** Console (Text-based)  
- **Data Structures:** Vector (dynamic array), custom classes  
- **Algorithm:** Merge Sort  

---

## 📂 Folder Structure

```plaintext
FindNest/
├── README.md
├── Project-Documents/
├── FindNest.cpp

```
---
## 🎉 Acknowledgments

- Developed while learning and practicing different types of algorithms in C++.  
- Thanks to **Faculty and Team Mates** who helped **review and improve** this project.  

Happy Learning with **FindNest**! 🌟
---
