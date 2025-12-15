# Assignment 3 — Matrix Multiplication Performance (SRB)

## Title
Matrix Multiplication Using Row-Major and Column-Major Access Patterns

## Objective
To compare execution time of matrix multiplication using two different memory-access strategies and analyze their performance impact.

## Theory
Matrix multiplication is a computationally intensive task. Its performance depends heavily on how data is accessed in memory.  
- **Row-major access** follows the natural storage order in C++.
- **Column-major-like access** attempts to optimize cache utilization by improving locality.

Better cache locality reduces cache misses, resulting in faster execution.

## Algorithm

### Step 1: Initialize Matrices
- Fill A with values `i + j`
- Fill B with values `i - j`

### Step 2: Row-Major Multiplication
```
For i in rows:
    For j in columns:
        For k in range:
            C[i][j] += A[i][k] * B[k][j]
```

### Step 3: Column-Major Multiplication
```
For i in rows:
    For k in range:
        temp = A[i][k]
        For j in columns:
            C[i][j] += temp * B[k][j]
```

### Step 4: Measure Execution Time

## C++ Source Code

```cpp
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

const int N = 500;

void initialize(vector<vector<int>>& A, vector<vector<int>>& B) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
}

void multiplyRowMajor(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j]; 
            }
            C[i][j] = sum;
        }
}

void multiplyColumnMajor(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    for (int i = 0; i < N; i++)
        for (int k = 0; k < N; k++) {
            int temp = A[i][k];
            for (int j = 0; j < N; j++) {
                C[i][j] += temp * B[k][j]; 
            }
        }
}

int main() {
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    vector<vector<int>> C(N, vector<int>(N, 0));

    initialize(A, B);

    cout << "Matrix multiplication using Row-Major order...\n";
    auto start = high_resolution_clock::now();
    multiplyRowMajor(A, B, C);
    auto end = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration1.count() << " ms\n";

    for (int i = 0; i < N; i++)
        fill(C[i].begin(), C[i].end(), 0);

    cout << "\nMatrix multiplication using Column-Major-like access...\n";
    start = high_resolution_clock::now();
    multiplyColumnMajor(A, B, C);
    end = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration2.count() << " ms\n";

    return 0;
}
```

# Output — Matrix Multiplication Program (SRB)

This file contains the **sample console output in text format**.

```
Matrix multiplication using Row-Major order...
Time taken: 4423 ms

Matrix multiplication using Column-Major-like access...
Time taken: 2331 ms
```

## Conclusion
Memory access patterns significantly impact algorithmic efficiency, especially in large datasets.  
Column-major-like access is more cache-friendly and offers better performance.

