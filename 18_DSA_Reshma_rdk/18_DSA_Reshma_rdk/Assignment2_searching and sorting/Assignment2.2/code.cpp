/*WAP to implement Bubble sort and Quick Sort on a 1D array of Student structure (contains
 student_name, student_roll_no, total_marks), with key as student_roll_no. And count the number of
  swap performed by each method.*/

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

