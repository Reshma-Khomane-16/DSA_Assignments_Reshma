## Assignment - 5 Employee Sorting Using Merge Sort and Selection Sort

## **Title**
Employee Sorting Using Merge Sort and Selection Sort

## **Objective**
To arrange a list of employees based on the average of their height and weight using:
- **Selection Sort**
- **Merge Sort**

Then analyze their time complexities and conclude which algorithm is more efficient.

---

## **Theory**

### **Selection Sort**
- A comparison-based sorting technique.
- Repeatedly finds the minimum element and places it at the correct position.
- **Time Complexity:** O(n²)
- **Best used for:** Small datasets

### **Merge Sort**
- A divide-and-conquer sorting algorithm.
- Divides the array into halves, recursively sorts them, and merges the sorted halves.
- **Time Complexity:** O(n log n)
- **Best used for:** Large datasets

---

## **Algorithm**

### **Selection Sort Algorithm**
1. Start from index `0`
2. Find the minimum element in the unsorted part
3. Swap it with the current index
4. Repeat for all positions

---

### **Merge Sort Algorithm**
1. Divide array into two halves
2. Recursively apply merge sort on both halves
3. Merge the two sorted halves
4. Continue until fully sorted

---

## **Code (C++ Implementation)**

```cpp
// Write a program to arrange the list of employees as per 
// the average of their height and weight using Merge and Selection sorting methods.

#include <iostream>
using namespace std;

struct Employee {
    string name;
    float height;
    float weight;
    float avg;
};

// Calculate average
void calculateAvg(Employee emp[], int n) {
    for (int i = 0; i < n; i++) {
        emp[i].avg = (emp[i].height + emp[i].weight) / 2.0;
    }
}

// Display function
void display(Employee emp[], int n) {
    cout << "\nName\tHeight\tWeight\tAverage\n";
    for (int i = 0; i < n; i++) {
        cout << emp[i].name << "\t"
             << emp[i].height << "\t"
             << emp[i].weight << "\t"
             << emp[i].avg << endl;
    }
}

// Selection Sort
void selectionSort(Employee emp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (emp[j].avg < emp[minIndex].avg)
                minIndex = j;
        }
        swap(emp[i], emp[minIndex]);
    }
}

// Merge Function
void merge(Employee emp[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[50], R[50];

    for (int i = 0; i < n1; i++)
        L[i] = emp[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = emp[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg)
            emp[k++] = L[i++];
        else
            emp[k++] = R[j++];
    }

    while (i < n1)
        emp[k++] = L[i++];

    while (j < n2)
        emp[k++] = R[j++];
}

// Merge Sort
void mergeSort(Employee emp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(emp, left, mid);
        mergeSort(emp, mid + 1, right);
        merge(emp, left, mid, right);
    }
}

// --------------------------- MAIN PROGRAM ---------------------------

int main() {
    int n_rdk, choice_rdk;   // ONLY main variables have _rdk
    Employee emp_rdk[50];

    cout << "Enter number of employees: ";
    cin >> n_rdk;

    for (int i_rdk = 0; i_rdk < n_rdk; i_rdk++) {
        cout << "\nEnter Employee " << i_rdk + 1 << " Name: ";
        cin >> emp_rdk[i_rdk].name;

        cout << "Enter Height: ";
        cin >> emp_rdk[i_rdk].height;

        cout << "Enter Weight: ";
        cin >> emp_rdk[i_rdk].weight;
    }

    calculateAvg(emp_rdk, n_rdk);

    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Display Employees";
        cout << "\n2. Selection Sort";
        cout << "\n3. Merge Sort";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                display(emp_rdk, n_rdk);
                break;

            case 2:
                selectionSort(emp_rdk, n_rdk);
                cout << "\nSorted using Selection Sort.\n";
                display(emp_rdk, n_rdk);
                break;

            case 3:
                mergeSort(emp_rdk, 0, n_rdk - 1);
                cout << "\nSorted using Merge Sort.\n";
                display(emp_rdk, n_rdk);
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid option!";
        }
    } while (choice_rdk != 4);

    return 0;
}

```

---

## **Output (Sample)**

```
C:\Users\Pioneer\Desktop\DSA_CPP>10selectio
n_merge.exe
Enter number of employees: 5

Enter Employee 1 Name: Reshma
Enter Height: 5.4
Enter Weight: 46

Enter Employee 2 Name: Prachi
Enter Height: 5.1
Enter Weight: 48

Enter Employee 3 Name: Rohan
Enter Height: 5.6
Enter Weight: 50

Enter Employee 4 Name: Navy
Enter Height: 4.8
Enter Weight: 56

Enter Employee 5 Name: Reena
Enter Height: 5.5
Enter Weight: 54

===== MENU =====
1. Display Employees
2. Selection Sort
3. Merge Sort
4. Exit
Enter your choice: 2

Sorted using Selection Sort.

Name    Height  Weight  Average
Reshma  5.4     46      25.7
Prachi  5.1     48      26.55
Rohan   5.6     50      27.8
Reena   5.5     54      29.75
Navy    4.8     56      30.4

===== MENU =====
1. Display Employees
2. Selection Sort
3. Merge Sort
4. Exit
Enter your choice: 3

Sorted using Merge Sort.

Name    Height  Weight  Average
Reshma  5.4     46      25.7
Prachi  5.1     48      26.55
Rohan   5.6     50      27.8
Reena   5.5     54      29.75
Navy    4.8     56      30.4


---

## **Conclusion**
- **Selection Sort:** O(n²) – inefficient for large datasets  
- **Merge Sort:** O(n log n) – significantly faster  
- **Final Conclusion:**  
  **Merge Sort is the better algorithm for sorting employee data based on average height and weight.**

---
