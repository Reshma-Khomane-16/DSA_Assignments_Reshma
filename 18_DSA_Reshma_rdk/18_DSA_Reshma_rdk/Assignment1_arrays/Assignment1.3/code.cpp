/*Write a program to construct and verify a magic square of order 'n' (for both even & odd) 
such that all rows, columns, and diagonals sum to the same value.*/

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
