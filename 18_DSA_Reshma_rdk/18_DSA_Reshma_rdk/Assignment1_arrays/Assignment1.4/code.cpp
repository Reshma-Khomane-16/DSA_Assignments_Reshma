/*Develop a program to identify and efficiently store a sparse matrix using compact representation
 and perform basic operations like display and simple transpose.*/

#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int value;
};

int convertToCompact(int matrix[10][10], int rows, int cols, Element compact[]) {
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

void displayMatrix(int matrix[10][10], int rows, int cols) {
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void displayCompact(Element compact[], int size) {
    cout << "\nCompact Representation (row, col, value):\n";
    for (int i = 0; i < size; i++)
        cout << compact[i].row << "\t" << compact[i].col << "\t" << compact[i].value << endl;
}

void simpleTranspose(Element compact[], Element transposed[], int size) {
    for (int i = 0; i < size; i++) {
        transposed[i].row = compact[i].col;
        transposed[i].col = compact[i].row;
        transposed[i].value = compact[i].value;
    }
}

int main() {
    int matrix[10][10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    displayMatrix(matrix, rows, cols);

    Element compact[100];
    int size = convertToCompact(matrix, rows, cols, compact);

    displayCompact(compact, size);

    Element transposed[100];
    simpleTranspose(compact, transposed, size);

    cout << "\nSimple Transpose (row, col, value):\n";
    displayCompact(transposed, size);

    return 0;
}