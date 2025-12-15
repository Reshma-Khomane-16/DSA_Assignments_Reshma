/*Write a program to arrange the list of employees as per the average of their height and weight 
by using Merge and Selection sorting method. Analyse their time complexities and conclude which 
algorithm will take less time to sort the list.*/

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
