# Title
Roll Number Assignment Using Binary Search Tree

# Objective
To assign roll numbers to students based on their previous year's marks using a Binary Search Tree, where the topper receives roll number 1.

# Theory
A Binary Search Tree (BST) allows data to be arranged in a hierarchical structure where the left child contains greater marks (higher rank) and the right child contains lesser marks. By performing an inorder traversal on this BST, the students can be arranged in decreasing order of marks. This enables assigning roll numbers starting from 1 for the topper.

# Algorithm
1. Start with an empty BST.
2. For each student:
   - Read the name and marks.
   - Insert the student into the BST such that higher marks go to the left subtree.
3. Initialize roll number as 1.
4. Perform an inorder traversal of the BST:
   - For each visited node, assign the current roll number.
   - Increment the roll number.
5. Display the assigned roll numbers.

# Code
```
/*Write a program, using trees, to assign the roll nos. to the students of your class as per their
 previous years result. i.e topper will be roll no. 1*/
#include <iostream>
using namespace std;

// Node of BST
struct Node {
    int marks;
    string name;
    Node *left, *right;
};

// Create new node
Node* createNode(int marks, string name) {
    Node* temp = new Node;
    temp->marks = marks;
    temp->name = name;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert according to marks (higher marks to RIGHT for descending display)
Node* insertNode(Node* root, int marks, string name) {
    if (root == NULL)
        return createNode(marks, name);

    if (marks > root->marks)
        root->right = insertNode(root->right, marks, name);
    else
        root->left = insertNode(root->left, marks, name);

    return root;
}

// Display students with roll numbers (Descending => Topper first)
void assignRollNumbers(Node* root, int &roll_rdk) {
    if (root == NULL) return;

    // Right subtree first → higher marks first
    assignRollNumbers(root->right, roll_rdk);

    cout << "Roll No. " << roll_rdk << " : " 
         << root->name << " (Marks: " << root->marks << ")\n";
    roll_rdk++;

    assignRollNumbers(root->left, roll_rdk);
}

int main() {
    Node* root_rdk = NULL;
    int choice_rdk;
    int marks_rdk;
    string name_rdk;

    while (true) {
        cout << "\n--- Student Roll Number Assignment System (Using BST) ---\n";
        cout << "1. Insert Student Record\n";
        cout << "2. Display Roll Numbers\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        if (choice_rdk == 1) {
            cout << "Enter student name: ";
            cin >> name_rdk;
            cout << "Enter previous year marks: ";
            cin >> marks_rdk;
            root_rdk = insertNode(root_rdk, marks_rdk, name_rdk);
            cout << "Student added successfully!\n";
        }
        else if (choice_rdk == 2) {
            int roll_rdk = 1;
            cout << "\n--- Assigned Roll Numbers ---\n";
            assignRollNumbers(root_rdk, roll_rdk);
        }
        else if (choice_rdk == 3) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}


```

# Output
Enter number of students: 3
Enter name and marks: Shivam 98
Enter name and marks: Sahil 97
Enter name and marks: Onkar 96

Assigned Roll Numbers:
Roll No. 1 : Shivam (98)
Roll No. 2 : Sahil (97)
Roll No. 3 : Onkar (96)
PS C:\Users\sneha\New folder\DSA.cpp> 

# Dry Run
Example input:
- Students: A(95), B(88), C(98)

BST structure (marks):
        C(98)
                      A(95)
                            B(88)

Inorder traversal gives:  
C → A → B

Assigned roll numbers:
1. C  
2. A  
3. B

# Conclusion
Binary Search Tree efficiently arranges students based on marks, and inorder traversal ensures correct roll number assignment based on academic performance.
