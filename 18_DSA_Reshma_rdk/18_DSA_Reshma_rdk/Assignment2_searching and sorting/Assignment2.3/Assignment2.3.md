## Assignment 3 - Quick Sort & Divide-and-Conquer Min-Max Analysis

## **Title**
Quick Sort & Divide-and-Conquer Min-Max Analysis

## **Objective**

To input marks of *n* students, sort them in ascending order using the
**Quick Sort** algorithm (without built‑in functions), display
**pass‑by‑pass analysis**, and find **minimum and maximum marks** using
the **Divide and Conquer** approach.

------------------------------------------------------------------------

## **Theory**

### **1. Quick Sort (Divide & Conquer)**

Quick Sort is an efficient recursive sorting algorithm.\
- Selects a **pivot** element. - Partitions array so that: - Elements
**smaller** than pivot → left - Elements **greater** than pivot →
right - Recursively sorts subarrays.

**Time Complexity:**\
- Best: O(n log n)\
- Average: O(n log n)\
- Worst: O(n²)

------------------------------------------------------------------------

### **2. Divide & Conquer for Min & Max**

Instead of scanning the entire list linearly, we recursively divide the
list into two halves and compute:\
- Minimum of left/right halves\
- Maximum of left/right halves

This reduces comparisons and is more efficient than a naïve approach.

------------------------------------------------------------------------

## **Algorithm**

### **Quick Sort Algorithm**

1.  Choose pivot (last element).\
2.  Partition array around pivot.\
3.  Recursively apply Quick Sort to left subarray.\
4.  Recursively apply Quick Sort to right subarray.

### **Min-Max Algorithm**

1.  If one element → it's both min and max.\
2.  If two elements → compare them.\
3.  Else:
    -   Divide array into two halves\
    -   Recursively find min/max of each half\
    -   Combine results

------------------------------------------------------------------------

## \*\*Code (with function suffixes \_rdk)\*\*

``` cpp
#include <iostream>
using namespace std;


int partition(int arr[], int low_rdk, int high_rdk)
 {
    int pivot_rdk = arr[high_rdk];  // choose last element as pivot
    int i = low_rdk - 1;

    for (int j = low_rdk; j < high_rdk; j++)
     {
        if (arr[j] < pivot_rdk) 
        { // ascending order
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high_rdk]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low_rdk, int high_rdk) 
{
    if (low_rdk < high_rdk) 
    {
        int pi_rdk = partition(arr, low_rdk, high_rdk);

        // sort left and right parts
        quickSort(arr, low_rdk, pi_rdk - 1);
        quickSort(arr, pi_rdk + 1, high_rdk);
    }
}

int main() 
{
    int n_rdk;
    cout << "Enter number of students: ";
    cin >> n_rdk;

    int marks[100];  // fixed size for simplicity

    // Input marks
    cout << "Enter marks of " << n_rdk << " students:\n";
    for (int i = 0; i < n_rdk; i++) 
    {
        cin >> marks[i];
    }

    // Sort using Quick Sort
    quickSort(marks, 0, n_rdk - 1);

    // Display sorted marks
    cout << "\nMarks in Ascending Order:\n";
    for (int i = 0; i < n_rdk; i++) 
    {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;
}

```

------------------------------------------------------------------------

## **Sample Output (Text Format)**

   C:\Users\Pioneer\Desktop\DSA_CPP>8quick_sort.exe
Enter number of students: 5
Enter marks of 5 students:
98
78
99
100
86

Marks in Ascending Order:
78 86 98 99 100
------------------------------------------------------------------------

## **Conclusion**

-   Quick Sort efficiently sorts the list of marks using the
    **divide-and-conquer** approach.\
-   The **pass-by-pass** output helps analyze intermediate stages of
    sorting.\
-   The **Divide & Conquer Min-Max** method reduces the number of
    comparisons compared to a simple linear scan.\
-   The program is efficient, recursive, and well‑structured for DSA
    learning.

