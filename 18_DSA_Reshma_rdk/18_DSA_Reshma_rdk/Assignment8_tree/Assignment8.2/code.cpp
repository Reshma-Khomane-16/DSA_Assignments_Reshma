/*Write a program to illustrate operations on a BST holding numeric keys.
The menu must include: • Insert • Delete • Find • Show*/	
#include <iostream>
using namespace std;

// BST Node
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int key) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Insert key
Node* insert(Node* root, int key) {
    if (root == nullptr) return createNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

// Find minimum node
Node* findMin(Node* root) {
    while (root && root->left != nullptr) root = root->left;
    return root;
}

// Delete key
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { Node* temp = root->right; delete root; return temp; }
        else if (!root->right) { Node* temp = root->left; delete root; return temp; }
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Search key
bool find(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    return (key < root->key) ? find(root->left, key) : find(root->right, key);
}

// Inorder traversal
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main menu
int main() {
    Node* root = nullptr;
    int choice_rdk, key_rdk;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Find\n";
        cout << "4. Show (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key_rdk;
                root = insert(root, key_rdk);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key_rdk;
                root = deleteNode(root, key_rdk);
                break;
            case 3:
                cout << "Enter key to find: ";
                cin >> key_rdk;
                if (find(root, key_rdk)) cout << key_rdk << " found.\n";
                else cout << key_rdk << " not found.\n";
                break;
            case 4:
                cout << "BST Inorder: ";
                inorder(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_rdk != 5);

    return 0;
}
