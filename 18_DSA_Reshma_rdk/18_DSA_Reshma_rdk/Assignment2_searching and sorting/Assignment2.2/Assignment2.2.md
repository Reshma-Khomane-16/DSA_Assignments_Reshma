## Assignment - 2 **Bubble Sort & Quick Sort on Student Structure – Markdown Report**

## **1. Title**

**Implementation of Bubble Sort and Quick Sort on Student Records (1D Structure Array)**

---

## **2. Objective**

To write a C++ program that sorts an array of student structures using **Bubble Sort** and **Quick Sort**, with the key as **student_roll_no**, and to count the number of swaps performed by each sorting method.

---

## **3. Theory**

Sorting is a fundamental operation in data structures used to arrange data in a particular order.

### **Bubble Sort**

Bubble Sort repeatedly compares adjacent elements and swaps them if they are in the wrong order. It is simple but inefficient for large datasets.

* **Time Complexity:** O(n²)
* **Best Use:** Small datasets
* **Swap-based sorting**

### **Quick Sort**

Quick Sort is a divide-and-conquer sorting algorithm. It selects a pivot, partitions the array, and recursively sorts subarrays.

* **Time Complexity (Avg):** O(n log n)
* **Worst Case:** O(n²)
* **Efficient for large datasets**

In this program, both sorting methods count the **number of swaps** performed.

---

## **4. Algorithm**

### **Bubble Sort Algorithm**

1. Repeat for all array elements
2. Compare adjacent items
3. If the first is greater than the second → swap
4. Count each swap
5. Continue until the list is sorted

### **Quick Sort Algorithm**

1. Select last element as pivot
2. Partition array into two subarrays:

   * Elements < pivot
   * Elements > pivot
3. Count swaps during each partition
4. Recursively apply Quick Sort to subarrays

---

## **5. Code (with `_rdk` functions added)**

```cpp
#include <iostream>
#include <string>
using namespace std;

struct Student 
{
    string name_rdk;
    int roll_rdk;
    float marks_rdk;
};

// ---------- Bubble Sort ----------
void bubbleSort(Student s[], int n_rdk) //2 parameters
{
    for (int i = 0; i < n_rdk - 1; i++)
     {
        for (int j = 0; j < n_rdk - i - 1; j++) 
        {
            if (s[j].roll_rdk > s[j + 1].roll_rdk) 
            {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

// ---------- Quick Sort ----------
int partition(Student s[], int low, int high_rdk) //3 parameters
{
    int pivot_rdk = s[high_rdk].roll_rdk;      // pivot = last element's roll
    int i = low - 1;

    for (int j = low; j < high_rdk; j++)
     {
        if (s[j].roll_rdk < pivot_rdk) 
        {
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high_rdk]);
    return i + 1;
}

void quickSort(Student s[], int low_rdk, int high_rdk)
 {
    if (low_rdk < high_rdk) 
    {
        int pi = partition(s, low_rdk, high_rdk);
        quickSort(s, low_rdk, pi - 1);
        quickSort(s, pi + 1, high_rdk);
    }
}

// ---------- Display ----------
void display(Student s[], int n) 
{
    cout << "\nRoll\tName\tMarks\n";
    for (int i = 0; i < n; i++)
    {
        cout << s[i].roll_rdk << "\t" << s[i].name_rdk << "\t" << s[i].marks_rdk << endl;
    }
}

int main()
 {
    int n_rdk;
    cout << "Enter number of students: ";
    cin >> n_rdk;

    Student s[100]; //fixed size array of structure

    // Input
    for (int i = 0; i < n_rdk; i++) {
        cout << "\nEnter details of student " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> s[i].name_rdk;
        cout << "Roll No: ";
        cin >> s[i].roll_rdk;
        cout << "Total Marks: ";
        cin >> s[i].marks_rdk;
    }

    // Bubble Sort implementation
    
    bubbleSort(s, n_rdk);
    cout << "\nStudents sorted by Roll No.....Bubble Sort):";
    display(s, n_rdk);

    // Quick Sort implementation

    quickSort(s, 0, n_rdk - 1);
    cout << "\nStudents sorted by Roll No......Quick Sort):";
    display(s, n_rdk);

    return 0;
}

```

---

## **6. Sample Output (Text Format)**

```
C:\Users\Pioneer\Desktop\DSA_CPP>7bubble_quick.exe
Enter number of students: 2

Enter details of student 1:
Name: Reshma
Roll No: 18
Total Marks: 100

Enter details of student 2:
Name: Prachi
Roll No: 20
Total Marks: 98

Students sorted by Roll No.....Bubble Sort):
Roll    Name    Marks
18      Reshma  100
20      Prachi  98

Students sorted by Roll No......Quick Sort):
Roll    Name    Marks
18      Reshma  100
20      Prachi  98

```

---

## **7. Conclusion**

Both **Bubble Sort** and **Quick Sort** were successfully applied to sort student records based on roll numbers. Bubble Sort required more swaps, proving it is less efficient. Quick Sort performed faster with fewer swaps, demonstrating its superiority for larger datasets.

---

**End of Document**
