## Assignment 4 - Sparse Matrix Project

## Title

Sparse Matrix Representation and Operations Using Compact Form

## Objective

To efficiently store a sparse matrix using compact representation and
perform operations such as display and simple transpose.

## Theory

A sparse matrix is a matrix in which most of the elements are zero.
Storing all elements wastes memory, so compact representation stores
only non‑zero values along with their row and column indices.\
This reduces the space complexity and improves performance for matrix
operations.

## Algorithm

### 1. Convert to Compact Form

1.  Read the matrix.
2.  Traverse each element.
3.  If the element is non‑zero, store (row, column, value) in a
    structure.
4.  Return total count of non‑zero elements.

### 2. Simple Transpose

1.  For each compact element:
    -   Swap row and column values.
2.  Store in a new compact array.

### 3. Display

-   Print the original matrix.
-   Print the compact representation.
-   Print the transposed compact representation.

## Code

``` cpp
// C++ Program for Sparse Matrix using Compact Representation

#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

int convertToCompact_srb(int matrix[10][10], int rows, int cols, Element compact[]) {
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] != 0) {
                compact[k].row = i;
                compact[k].col = j;
                compact[k].value = matrix[i][j];
                k++;
            }
    return k;
}

void displayMatrix_srb(int matrix[10][10], int rows, int cols) {
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void displayCompact_srb(Element compact[], int size) {
    cout << "\nCompact Representation (row, col, value):\n";
    for (int i = 0; i < size; i++)
        cout << compact[i].row << "\t" << compact[i].col << "\t" << compact[i].value << endl;
}

void simpleTranspose_srb(Element compact[], Element transposed[], int size) {
    for (int i = 0; i < size; i++) {
        transposed[i].row = compact[i].col;
        transposed[i].col = compact[i].row;
        transposed[i].value = compact[i].value;
    }
}
```

## Output

    Enter number of rows and columns: 3 3
    Enter matrix elements:
    1 0 2
    0 0 3
    4 0 0

    Matrix:
    1   0   2
    0   0   3
    4   0   0

    Compact Representation:
    0 0 1
    0 2 2
    1 2 3
    2 0 4

    Transpose:
    0 0 1
    2 0 2
    2 1 3
    0 2 4

## Conclusion

The sparse matrix representation using compact form significantly
reduces memory usage by storing only non‑zero elements.\
The simple transpose operation is efficient because it processes only
the compact elements instead of the full matrix.
