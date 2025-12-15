/*Write a program to perform Binary Search Tree (BST) operations (Create, Insert, Delete,Levelwise
 display )*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *root = NULL;

// Create new node
node* createNode(int x) {
    node *temp = new node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert function
node* insert(node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Find minimum for delete operation
node* findMin(node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete function
node* deleteNode(node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {

        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        } 
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Level-order Display (using simple array queue)
void levelDisplay(node* root) {
    if (root == NULL) {
        cout << "\nTree is empty.\n";
        return;
    }

    node* q[100];
    int front = 0, rear = 0;

    q[rear++] = root;

    cout << "\nLevel-wise Display: ";

    while (front < rear) {
        node* temp = q[front++];
        cout << temp->data << " ";

        if (temp->left != NULL)
            q[rear++] = temp->left;

        if (temp->right != NULL)
            q[rear++] = temp->right;
    }
    cout << "\n";
}

int main() {

    int choice_rdk, value_rdk;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Level-wise Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch(choice_rdk) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value_rdk;
                root = insert(root, value_rdk);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value_rdk;
                root = deleteNode(root, value_rdk);
                break;

            case 3:
                levelDisplay(root);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice_rdk != 4);

    return 0;
}
