# Implement Your Own String Class in C++

## 📌 Project Description

This project implements a custom `String` class in C++ using **dynamic memory allocation** and a dynamically allocated character array.

The project demonstrates how basic string operations and operator overloading can be implemented without using the C++ `std::string` class or directly using the standard string manipulation functions.

## 🎯 Objectives

* Understand dynamic memory allocation.
* Implement a custom String class using a character array.
* Understand constructors, copy constructors, assignment operators, and destructors.
* Implement operator overloading.
* Implement string manipulation functions using character-by-character operations.
* Demonstrate proper memory management and deep copying.

## ✨ Features

### Constructors

The `String` class implements:

* Default constructor
* Parameterized constructor `String(const char *)`
* Copy constructor
* Internal size-based constructor used for dynamic allocation

### Operator Overloading

The following operators are implemented:

* Assignment operator `=`
* Concatenation operator `+`
* Character access operator `[]`
* Comparison operators:

  * `<`
  * `>`
  * `<=`
  * `>=`
  * `==`
  * `!=`
* Stream insertion operator `<<`
* Stream extraction operator `>>`

### String Functions

The following user-defined string functions are implemented:

* `strlen()`
* `strcpy()`
* `strncpy()`
* `strcmp()`
* `strncmp()`
* `strcat()`
* `strncat()`
* `strrev()`
* `strupr()`
* `strlwr()`
* `strchr()`
* `strrchr()`
* `strstr()`

All these functions operate directly on the custom `String` objects.

## 🧠 Concepts Used

* Classes and Objects
* Constructors
* Copy Constructor
* Deep Copy
* Dynamic Memory Allocation
* Dynamic Character Arrays
* Operator Overloading
* Friend Functions
* Pointers
* Character Arrays
* Manual String Manipulation
* Destructor and Memory Deallocation

## 💾 Dynamic Memory Management

The class uses dynamically allocated character arrays:

```cpp
char *s;
```

Memory is allocated according to the required string length and released using:

```cpp
delete []s;
```

The copy constructor and assignment operator perform **deep copying** so that different `String` objects maintain separate memory.

## 🧪 Testing

The `main()` function demonstrates the implementation of:

* Default constructor
* Parameterized constructor
* Copy constructor
* Assignment operator
* `[]` operator
* `+` operator
* All comparison operators
* All implemented string functions

The program also displays the results before and after modification for functions such as `strcpy()`, `strncpy()`, `strcat()`, `strncat()`, `strrev()`, `strupr()`, and `strlwr()`.

## ▶️ How to Compile and Run

### Using g++

Open a terminal in the project directory and compile:

```bash
g++ String.cpp -o String
```

Run the program:

### Windows

```bash
String.exe
```

### Linux / macOS

```bash
./String
```

## 📂 Project Structure

```text
implement-your-own-string-class-cpp/
│
├── String.cpp
├── README.md
└── sample_output.txt
```

## 📋 Sample Operations

Example operations demonstrated by the program:

```text
strlen()
strcpy()
strncpy()
strcmp()
strncmp()
strcat()
strncat()
strrev()
strupr()
strlwr()
strchr()
strrchr()
strstr()
```

## 📚 Learning Outcome

This project provides practical understanding of how a string class can be built from the ground up using C++ classes, pointers, dynamic memory allocation, operator overloading, and friend functions.

It also demonstrates the importance of **deep copy and proper memory management** when working with dynamically allocated memory.

## 👨‍💻 Author

**Krishna Kulkarni**

---

⭐ If you find this project useful, feel free to explore the implementation and learn how a custom String class works internally.
