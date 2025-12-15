/*Write a Program to create a Binary Tree and perform the following Recursive operations on it. 
a. Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes d. Mirror Image*/	
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// ------------------------ CREATE BINARY TREE ------------------------
Node* createTree() {
    int x;
    cout << "Enter value (-1 for no node): ";
    cin >> x;

    if (x == -1) {
        return nullptr;
    }

    Node* newNode = new Node(x);
    cout << "Enter LEFT child of " << x << endl;
    newNode->left = createTree();

    cout << "Enter RIGHT child of " << x << endl;
    newNode->right = createTree();

    return newNode;
}

// ------------------------ INORDER (Recursive) ------------------------
void inorder(Node* root) {
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// ------------------------ PREORDER (Recursive) ------------------------
void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// ------------------------ COUNT LEAF NODES ------------------------
int countLeaf(Node* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    return countLeaf(root->left) + countLeaf(root->right);
}

// ------------------------ MIRROR IMAGE ------------------------
Node* mirror(Node* root) {
    if (root == nullptr) return nullptr;

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);

    return root;
}

// ------------------------ MAIN MENU ------------------------
int main() {
    Node* root_rdk = nullptr;
    int choice_rdk;

    do {
        cout << "\n====== BINARY TREE MENU ======\n";
        cout << "1. Create Binary Tree\n";
        cout << "2. Inorder Traversal (Recursive)\n";
        cout << "3. Preorder Traversal (Recursive)\n";
        cout << "4. Count Leaf Nodes\n";
        cout << "5. Mirror Image\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            root_rdk = createTree();
            cout << "Binary Tree Created Successfully!\n";
            break;

        case 2:
            cout << "Inorder Traversal: ";
            inorder(root_rdk);
            cout << endl;
            break;

        case 3:
            cout << "Preorder Traversal: ";
            preorder(root_rdk);
            cout << endl;
            break;

        case 4:
            cout << "Number of Leaf Nodes: " << countLeaf(root_rdk) << endl;
            break;

        case 5:
            mirror(root_rdk);
            cout << "Mirror Image Created!\n";
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice! Try Again.\n";
        }

    } while (choice_rdk != 6);

    return 0;
}
