/*Write a program to efficiently search a particular employee record by using Tree data structure.
 Also sort the data on emp­id in ascending order.*/
#include <iostream>
#include <string>
using namespace std;

// Employee structure as BST node
struct Employee {
    int empid;
    string name;
    string dept;
    Employee* left;
    Employee* right;
};

// Create new employee node
Employee* createEmployee(int empid, string name, string dept) {
    Employee* newEmp = new Employee;
    newEmp->empid = empid;
    newEmp->name = name;
    newEmp->dept = dept;
    newEmp->left = newEmp->right = nullptr;
    return newEmp;
}

// Insert employee into BST based on empid
Employee* insertEmployee(Employee* root, int empid, string name, string dept) {
    if (!root) return createEmployee(empid, name, dept);
    if (empid < root->empid)
        root->left = insertEmployee(root->left, empid, name, dept);
    else if (empid > root->empid)
        root->right = insertEmployee(root->right, empid, name, dept);
    return root;
}

// Search employee by empid
Employee* searchEmployee(Employee* root, int empid) {
    if (!root || root->empid == empid) return root;
    if (empid < root->empid) return searchEmployee(root->left, empid);
    return searchEmployee(root->right, empid);
}

// Inorder traversal to display employees in ascending empid
void displayInorder(Employee* root) {
    if (root) {
        displayInorder(root->left);
        cout << "EmpID: " << root->empid 
             << ", Name: " << root->name 
             << ", Dept: " << root->dept << endl;
        displayInorder(root->right);
    }
}

// Main menu
int main() {
    Employee* root = nullptr;
    int choice_rdk, empid_rdk;
    string name_rdk, dept_rdk;

    do {
        cout << "\n--- Employee BST Menu ---\n";
        cout << "1. Add Employee\n";
        cout << "2. Search Employee by ID\n";
        cout << "3. Show All Employees (Ascending EmpID)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter EmpID: ";
                cin >> empid_rdk;
                cin.ignore(); // clear input buffer
                cout << "Enter Name: ";
                getline(cin, name_rdk);
                cout << "Enter Department: ";
                getline(cin, dept_rdk);
                root = insertEmployee(root, empid_rdk, name_rdk, dept_rdk);
                break;

            case 2:
                cout << "Enter EmpID to search: ";
                cin >> empid_rdk;
                {
                    Employee* emp_rdk = searchEmployee(root, empid_rdk);
                    if (emp_rdk)
                        cout << "Found! EmpID: " << emp_rdk->empid 
                             << ", Name: " << emp_rdk->name 
                             << ", Dept: " << emp_rdk->dept << endl;
                    else
                        cout << "Employee not found.\n";
                }
                break;

            case 3:
                cout << "\nEmployees in ascending EmpID:\n";
                displayInorder(root);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_rdk != 4);

    return 0;
}
