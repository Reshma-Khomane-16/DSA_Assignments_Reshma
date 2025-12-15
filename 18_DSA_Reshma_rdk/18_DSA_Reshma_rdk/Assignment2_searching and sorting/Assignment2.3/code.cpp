/*Write a program to input marks of n students Sort the marks in ascending order using the 
Quick Sort algorithm without using built-in library functions and analyse the sorting 
algorithm pass by pass. Find the minimum and maximum marks using Divide and 
(recursively).*/

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
