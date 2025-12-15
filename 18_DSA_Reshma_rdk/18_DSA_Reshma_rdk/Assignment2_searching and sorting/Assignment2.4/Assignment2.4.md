# **Bubble Sort on Student Structure**

## **1. Title**

**Implementation of Bubble Sort on Student Records to Assign Roll Numbers Based on Merit**

---

## **2. Objective**

To implement the **Bubble Sort algorithm** in C++ to sort students based on their previous year marks in **descending order**, assign roll numbers accordingly (topper = Roll No. 1), and analyze sorting **pass-by-pass**.

---

## **3. Theory**

Sorting is a fundamental operation used to arrange data in a specific order.

### **Bubble Sort Overview**

Bubble Sort works by repeatedly comparing adjacent elements and swapping them if they are in the wrong order.

- In this case, students with **higher marks should appear first**, so sorting is in **descending order**.
- After sorting, roll numbers are assigned sequentially (1, 2, 3, …).

### **Time Complexity**
- **Best Case:** O(n) (when already sorted)
- **Worst Case:** O(n²)
- **Average Case:** O(n²)

Bubble Sort is simple but inefficient for large datasets.

---

## **4. Algorithm**

### **Bubble Sort Algorithm (Descending Order)**

1. Repeat for all elements in the list  
2. Compare adjacent students  
3. If marks of student[j] < student[j+1], swap  
4. Print array after every pass  
5. Stop early if no swap occurs (optimization)

---

## **5. Code (Functions Modified with `_rdk`)**

```cpp
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

```

---

## **6. Sample Output (Text Format)**

```
C:\Users\Pioneer\Desktop\DSA_CPP>9bubble_so
rt.exe
Enter number of students: 5
Enter marks of 5 students:
98
78
67
99
100

After Pass 1: 98 78 99 100 67
After Pass 2: 98 99 100 78 67
After Pass 3: 99 100 98 78 67
After Pass 4: 100 99 98 78 67

Final Ranking (Topper = Roll 1):
Roll No 1 -> Marks: 100
Roll No 2 -> Marks: 99
Roll No 3 -> Marks: 98
Roll No 4 -> Marks: 78
Roll No 5 -> Marks: 67
```

---

## **7. Conclusion**

Bubble Sort was successfully implemented to sort student records by their marks. Since we sort in descending order, the topper receives **Roll No. 1**.  
Bubble Sort’s pass-by-pass analysis clearly shows how students move toward their correct positions. Although inefficient for large inputs, it is easy to understand and implement for small datasets.

---

**End of Document**
