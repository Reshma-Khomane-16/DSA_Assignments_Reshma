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
