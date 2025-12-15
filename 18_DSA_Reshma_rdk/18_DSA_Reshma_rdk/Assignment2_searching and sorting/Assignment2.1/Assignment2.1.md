## Assignment 1 -  **Student Search Program – Markdown Report**

## **1. Title**

**Identification of a Specific Student Using Linear Search in C++**

---

## **2. Objective**

To implement a program in C++ that identifies a student from a given list based on specific criteria such as name, year, division, and roll number using an appropriate searching method (Linear Search). Additionally, to understand how structured data can be stored and searched efficiently using arrays and user-defined structures.

---

## **3. Theory**

Searching is one of the fundamental operations in Data Structures. It is used to find the location of a particular element within a collection of data.

### **Linear Search**

Linear Search is the simplest searching technique. In this method, each element of the list is compared one by one with the target value until a match is found.

### **Characteristics of Linear Search:**

* Works on *unsorted data*.
* Time Complexity: **O(n)**.
* Easy to implement.
* Best suited for small datasets.

In this program, we use **Linear Search** to search for a student from a list based on:

* Name → "XYZ"
* Year → "SY"
* Division → "X"
* Roll No → **17**

A structure is used to store the details of each student, and an array of structures is used to store multiple students.

---

## **4. Algorithm**

1. Start the program.
2. Input the number of students.
3. Create an array of structure `Student`.
4. For each student, input:

   * Name
   * Department
   * Year
   * Division
   * Roll number
5. Set search criteria:

   * Name = "XYZ"
   * Year = "SY"
   * Division = "X"
   * Roll No = 17
6. Traverse the list using *Linear Search*.
7. For each student, compare the input fields with the search values.
8. If all values match:

   * Display student details.
   * Set flag = true
   * Break the loop.
9. If flag is false after traversal:

   * Display "Student not found".
10. Stop the program.

---

## **5. Code (with function using initials `_srb`)**

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string dept;
    string year;
    string div;
    int roll;
};

// Function to search student - SRB
void searchStudent_srb(Student students[], int n) {
    string searchName = "XYZ";
    string searchYear = "SY";
    string searchDiv = "X";
    int searchRoll = 17;

    bool found = false;

    for (int i = 0; i < n; i++) {
        if (students[i].year == searchYear &&
            students[i].div == searchDiv &&
            students[i].name == searchName &&
            students[i].roll == searchRoll) {

            cout << "\nStudent found!\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Department: " << students[i].dept << endl;
            cout << "Year: " << students[i].year << endl;
            cout << "Division: " << students[i].div << endl;
            cout << "Roll No: " << students[i].roll << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nStudent not found in the list.\n";
    }
}

int main() {
    int n;
    cout << "Enter total number of students: ";
    cin >> n;

    Student students[n];

    cout << "\nEnter details of students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << " details:\n";
        cout << "Name: ";
        cin >> students[i].name;
        cout << "Department: ";
        cin >> students[i].dept;
        cout << "Year (FY/SY/TY/BTech): ";
        cin >> students[i].year;
        cout << "Division: ";
        cin >> students[i].div;
        cout << "Roll number: ";
        cin >> students[i].roll;
    }

    // Call search function
    searchStudent_srb(students, n);

    return 0;
}
```

---

## **6. Sample Output (Text Format)**

```
Enter total number of students: 3

Enter details of students:

Student 1 details:
Name: ABC
Department: COMP
Year: SY
Division: X
Roll number: 10

Student 2 details:
Name: XYZ
Department: COMP
Year: SY
Division: X
Roll number: 17

Student 3 details:
Name: PQR
Department: IT
Year: TY
Division: B
Roll number: 22

Student found!
Name: XYZ
Department: COMP
Year: SY
Division: X
Roll No: 17
```

---

## **7. Conclusion**

The program successfully demonstrates how **Linear Search** can be applied to identify a specific student from a list. By using structures and arrays, the program efficiently stores and processes multiple student records. The searching logic works correctly by comparing multiple fields such as name, year, division, and roll number. This solution is simple, effective, and well-suited for small datasets found in academic scenarios.

---

**End of Document**
