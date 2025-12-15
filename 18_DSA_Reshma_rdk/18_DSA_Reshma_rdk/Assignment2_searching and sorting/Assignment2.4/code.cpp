/*Write a program using Bubble sort algorithm, assign the roll nos. to the students of your
 class as per their previous years result.i.e. topper will be roll no. 1 and analyse the sorting 
 algorithm pass by pass.*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[100];   // marks of students
    int roll[100];    // roll numbers after sorting

    // Input marks
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        roll[i] = i + 1; // initial roll no. (just student index)
    }

    // ---------- Bubble Sort (Descending) ----------
    for (int pass = 0; pass < n - 1; pass++) {
        for (int j = 0; j < n - pass - 1; j++) {
            if (marks[j] < marks[j + 1]) { // swap if next is greater
                swap(marks[j], marks[j + 1]);
                swap(roll[j], roll[j + 1]);
            }
        }

        // Show array after each pass
        cout << "\nAfter Pass " << pass + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << marks[k] << " ";
        }
    }

    // ---------- Final Result ----------
    cout << "\n\nFinal Ranking (Topper = Roll 1):\n";
    for (int i = 0; i < n; i++) {
        cout << "Roll No " << i + 1 << " -> Marks: " << marks[i] << endl;
    }

    return 0;
}
