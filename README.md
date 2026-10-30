# Implement Your Own String Class in C++

## 📌 Project Description

This project implements a custom `String` class in C++ using dynamic memory allocation and a dynamically allocated character array.

The main objective is to understand how string operations can be implemented manually using C++ classes, pointers, operator overloading, and friend functions without using the `std::string` class or standard string manipulation functions.

## 🎯 Objectives

- Implement a user-defined String class.
- Understand dynamic memory allocation.
- Implement constructors and destructors.
- Understand deep copy and memory management.
- Implement operator overloading.
- Create user-defined string manipulation functions.
- Perform file handling using overloaded stream operators.

## ✨ Features

### 1. Constructors

The following constructors are implemented:

- Default constructor
- Parameterized constructor `String(const char *)`
- Copy constructor
- Size-based constructor for dynamic allocation

### 2. Operator Overloading

The following operators are implemented:

- Assignment operator `=`
- Concatenation operator `+`
- Character access operator `[]`
- Comparison operators:
  - `<`
  - `>`
  - `<=`
  - `>=`
  - `==`
  - `!=`
- Stream insertion operator `<<`
- Stream extraction operator `>>`

### 3. User-Defined String Functions

The project implements the following 13 string functions manually:

| Function | Description |
|---|---|
| `strlen()` | Finds the length of a string |
| `strcpy()` | Copies one string into another |
| `strncpy()` | Copies a specified number of characters |
| `strcmp()` | Compares two strings |
| `strncmp()` | Compares a specified number of characters |
| `strcat()` | Concatenates two strings |
| `strncat()` | Concatenates a specified number of characters |
| `strrev()` | Reverses a string |
| `strupr()` | Converts lowercase characters to uppercase |
| `strlwr()` | Converts uppercase characters to lowercase |
| `strchr()` | Finds the first occurrence of a character |
| `strrchr()` | Finds the last occurrence of a character |
| `strstr()` | Finds a substring within a string |

All functions are implemented using loops, pointers, and character manipulation.

## 📂 File Handling

File handling is implemented using the overloaded extraction operator `>>`.

The program performs the following operations:

1. The default constructor creates an empty String object.
2. The input file `input1.txt` is opened using `ifstream`.
3. The extraction operator first counts the total number of characters in the file.
4. Dynamic memory is allocated based on the character count.
5. The complete file content, including spaces and newline characters, is read into the String object.
6. The insertion operator `<<` displays the file contents.

This demonstrates dynamic memory allocation based on the actual file size.

## 🧠 Concepts Used

- Classes and Objects
- Constructors and Destructors
- Copy Constructor
- Deep Copy
- Dynamic Memory Allocation
- Character Arrays
- Pointers
- Operator Overloading
- Friend Functions
- File Handling
- Stream Operators
- Manual String Manipulation

## 💾 Memory Management

The String class uses a dynamically allocated character pointer:

```cpp
char *s;
```

Memory is allocated according to the required string length and released using:

```cpp
delete []s;
```

The copy constructor and assignment operator implement deep copying to ensure that separate String objects maintain independent memory.

## 🧪 Testing

The `main()` function demonstrates:

- Reading string data from a file.
- Default constructor.
- Parameterized constructor.
- Copy constructor.
- Assignment operator.
- Character access using `[]`.
- String concatenation using `+`.
- All six comparison operators.
- All 13 user-defined string functions.

## ▶️ How to Compile and Run

### Requirements

- C++ compiler (GCC / G++)
- Input file: `input1.txt`

### Compile

```bash
g++ mainfile.cpp -o String
```

### Run on Windows

```bash
String.exe
```

### Run on Linux / macOS

```bash
./String
```

**Note:** Keep `input1.txt` in the program's working directory when executing the program.

## 📁 Project Structure

```text
string-class-implementation-cpp/
│
├── README.md
├── mainfile.cpp
├── input1.txt
└── sample_output.png
```

## 📚 Learning Outcomes

Through this project, I gained practical experience in:

- Implementing a custom String class from scratch.
- Managing dynamically allocated memory.
- Understanding deep copy and object lifetime.
- Overloading operators for user-defined classes.
- Implementing string manipulation functions manually.
- Reading file contents using overloaded stream operators.

## 👨‍💻 Author

**Krishna Kulkarni**

---

⭐ This project was developed as part of C++ programming practice to strengthen concepts of object-oriented programming, operator overloading, dynamic memory allocation, and file handling.
