# Employee Record Search and Sorting using BST

## Title  
Employee Record Management using Binary Search Tree (BST)

## Objective  
To efficiently search employee records and display them in ascending order of Employee ID using a Binary Search Tree.

## Theory  
A **Binary Search Tree (BST)** is a hierarchical data structure in which each node has at most two children:
- Left child contains keys **smaller** than the parent  
- Right child contains keys **greater** than the parent  

BST allows efficient:
- **Insertion**  
- **Searching**  
- **Sorted traversal (Inorder)**  

Time complexities:  
- Best/Average: **O(log n)**  
- Worst (skewed tree): **O(n)**  

## Algorithm  

### Insertion  
1. If tree is empty, create a new node.  
2. If new ID < current node → go left.  
3. If new ID > current node → go right.  
4. Insert at the correct leaf.  

### Search  
1. Start from root.  
2. If ID matches → return node.  
3. If ID < node → search left.  
4. Else search right.  
5. If NULL reached → not found.  

### Display in Ascending Order  
Perform **inorder traversal**:  
- Traverse left  
- Visit node  
- Traverse right  

## Code  

```cpp
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

```

## Sample Output  

```
Enter number of employees: 4
Enter EmpID and Name: 1234 Shivam
Enter EmpID and Name: 2345 Sahil
Enter EmpID and Name: 5678 Onkar
Enter EmpID and Name: 8976 Harsh

Employees sorted by EmpID:
1234  Shivam
2345  Sahil
5678  Onkar
8976  Harsh

Enter EmpID to search: 2345
Found: 2345  Sahil
```

## Conclusion  
Using a Binary Search Tree makes searching and sorting employee records efficient.  
The inorder traversal naturally provides ascending order output.