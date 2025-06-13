# Sparse Matrix Operations

## Overview

# Documentation Comment

## Description
This code is part of a project that performs [brief description of the project's functionality]. It includes [specific functionality or feature provided by the code].

## How to Clone the Project
To clone the project, use the following command:
```bash
git clone https://github.com/Winnie-Irene/sparse_matrix.git
```

This project is a solution to *Programming Assignment 2: Sparse Matrix* from the **Data Structures and Algorithms for Engineers** course.

It implements a memory-efficient **sparse matrix** using a custom linked list and provides the following operations:

- Addition
- Subtraction
- Multiplication

The implementation avoids using the C++ Standard Template Library (STL), ensuring manual control over data structures and algorithms.

---

## Project Structure

```
dsa/
└── sparse_matrix/
    ├── code/
    │   └── src/  # Contains all C++ source and header files
    └── sample_inputs/  # Sample input matrix text files
```

---

## Input File Format

Matrix input files follow this format:

```
rows=3
cols=3
(0, 0, 2)
(0, 2, 5)
(1, 1, 3)
(2, 0, -1)
```

- `rows=` → Total number of rows  
- `cols=` → Total number of columns  
- Each `(row, column, value)` represents a non-zero matrix element  
- All unspecified elements are assumed to be `0`

---

## How to Compile and Run

Ensure `g++` is installed (e.g., via MinGW on Windows).

Navigate to the source directory in your terminal or PowerShell:

```bash
cd C:\Users\irene\dsa\sparse_matrix\code\src
```

Compile the source files to generate an executable:

```bash
g++ -o sparse_matrix main.cpp SparseMatrix.cpp
```

Run the program:

```bash
.\sparse_matrix
```

---

## Constraints

- No STL, regex, or built-in containers (manual data structures only)
- Input validation is included
- Exceptions are thrown for invalid input formats

---

## Author

**Irene Winnie**  
Coursework for *Data Structures and Algorithms for Engineers*

---

## License

This code is provided for academic use only. Redistribution or plagiarism is prohibited.

---
Let me know if you need:
- Output saved to a file instead of console
- Screenshots or Markdown badge section
- Automated test scripts for quick testing
