## iput

#include <iostream>
using namespace std;

struct Student {
    int roll;
    string name;
    int age;
};

class StudentRecord {
    Student s[50];
    int count;

public:
    StudentRecord() {
        count = 0;
    }

    void addStudent() {
        if (count >= 50) {
            cout << "Record Full!\n";
            return;
        }

        cout << "Enter Roll Number: ";
        cin >> s[count].roll;
        cout << "Enter Name: ";
        cin >> s[count].name;
        cout << "Enter Age: ";
        cin >> s[count].age;

        count++;
        cout << "Student Added Successfully!\n";
    }

    void searchStudent(int roll_rdk) {
        for (int i = 0; i < count; i++) {
            if (s[i].roll == roll_rdk) {
                cout << "\nStudent Found:\n";
                cout << "Roll No: " << s[i].roll << "\n";
                cout << "Name: " << s[i].name << "\n";
                cout << "Age: " << s[i].age << "\n";
                return;
            }
        }
        cout << "Student Not Found!\n";
    }

    void displayAll() {
        if (count == 0) {
            cout << "No Records Available!\n";
            return;
        }

        cout << "\n--- Student Records ---\n";
        for (int i = 0; i < count; i++) {
            cout << "Roll: " << s[i].roll
                 << ", Name: " << s[i].name
                 << ", Age: " << s[i].age << "\n";
        }
    }
};

int main() {
    StudentRecord obj_rdk;
    int choice_rdk, roll_rdk;

    do {
        cout << "\n--- Student Record Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student by Roll No\n";
        cout << "3. Display All Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            obj_rdk.addStudent();
            break;

        case 2:
            cout << "Enter Roll No to Search: ";
            cin >> roll_rdk;
            obj_rdk.searchStudent(roll_rdk);
            break;

        case 3:
            obj_rdk.displayAll();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice_rdk != 4);

    return 0;
}
