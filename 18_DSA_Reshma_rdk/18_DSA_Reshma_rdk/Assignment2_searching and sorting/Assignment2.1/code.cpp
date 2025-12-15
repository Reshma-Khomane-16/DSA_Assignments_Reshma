/*In Computer Engg. Dept. of VIT there are S.Y., T.Y., and B.Tech. students. Assume that
all these students are on ground for a function. We need to identify a student of S.Y.
 div. (X) whose name is "XYZ" and roll no. is "17". Apply appropriate Searching method
  to identify the required student.*/
  
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

    return 0;
}
