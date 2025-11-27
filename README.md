# C++ Console Login & Registration System 🔐

A lightweight, console-based authentication system built to explore core C++ syntax and data structures. This project serves as a practical bridge for developers transitioning from **C#** to **C++**.

## 🎯 Project Goal
The primary goal of this project is to move beyond isolated algorithmic problems (LeetCode) and build a cohesive application using the **C++ Standard Template Library (STL)**. It focuses on translating C# `Dictionary` and `List` concepts into their C++ equivalents.

**Key Learning Objectives:**
* **STL Mastery:** Using `std::unordered_map` for O(1) key-value lookups (simulating a database).
* **String Manipulation:** Handling `std::string` input and comparison.
* **I/O Streams:** Understanding C++ Input/Output (`cin` / `cout`) vs C# Console methods.
* **Control Flow:** implementing logic to handle duplicate users and validation.

## ⚙️ Features
* **User Registration:** * Accepts new username/password inputs.
    * Validates uniqueness using `map.count()` (prevents duplicates).
* **User Login:** * Authenticates credentials against stored data.
    * Provides feedback on success or failure.
* **Session Loop:** * The application runs continuously until the user explicitly selects "Exit".

## 🛠️ Tech Stack
* **Language:** C++ (C++17 recommended)
* **IDE:** Visual Studio 2022
* **Core Structure:** `std::unordered_map<string, string>`

## 🚀 Getting Started

### Prerequisites
* Visual Studio 2022 (with "Desktop development with C++" workload installed).

### Installation & Run
1.  Clone the repository:
    ```bash
    git clone [https://github.com/HarryJamesVowles/Cpp-Login-System.git](https://github.com/HarryJamesVowles/Cpp-Login-System.git)
    ```
2.  Open the `Console-Based Login and Registration System.sln` file in Visual Studio.
3.  Ensure **"Console-Based Login and Registration System"** is set as the **Startup Project** (Right-click project name -> Set as Startup Project).
4.  Press **F5** (or click the Green Play Button) to build and run.

## 🤝 Attribution
This project template and learning path were developed with guidance from **Google Gemini**, focusing on the syntax differences between C# and C++ for algorithmic problem solving.
````
