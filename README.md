# CodeAlpha_MatrixOperations

A menu-driven C program that performs matrix addition, multiplication and transpose. Built as **Task 2** of the CodeAlpha C Programming Internship.

## Features

- Matrix addition (A + B)
- Matrix multiplication (A x B)
- Transpose of a matrix
- Modular design: each operation is its own function
- Uses 2D arrays (up to 10 x 10)
- Input validation for sizes and values
- Automatically sets the required dimensions for multiplication (rows of B = columns of A)

## Getting Started

### Prerequisites

A C compiler such as GCC.

### Compile

```bash
gcc matrix_operations.c -o matrix_operations
```

### Run

```bash
./matrix_operations
```

On Windows, run `matrix_operations.exe` instead.

## Sample Run

```
=== Matrix Operations ===

1. Matrix Addition
2. Matrix Multiplication
3. Transpose
4. Exit
Enter your choice (1-4): 3
Rows (1-10): 2
Columns (1-10): 3
Enter elements of matrix A (2 x 3):
  A[0][0] = 1
  A[0][1] = 2
  A[0][2] = 3
  A[1][0] = 4
  A[1][1] = 5
  A[1][2] = 6

Transpose of A =
     1     4
     2     5
     3     6
```

## Functions

| Function | Purpose |
|----------|---------|
| `readMatrix` | Reads matrix elements from the user |
| `printMatrix` | Displays a matrix |
| `addMatrices` | Adds two matrices of the same size |
| `multiplyMatrices` | Multiplies an r1 x c1 matrix by a c1 x c2 matrix |
| `transposeMatrix` | Swaps rows and columns |
| `readInt` | Reads and validates an integer in a range |

## Concepts Used

- 2D arrays
- Functions and passing arrays to functions
- Nested loops
- `switch-case` menus and `do-while` loops
- Input validation

## Project Structure

```
CodeAlpha_MatrixOperations/
├── matrix_operations.c
└── README.md
```
