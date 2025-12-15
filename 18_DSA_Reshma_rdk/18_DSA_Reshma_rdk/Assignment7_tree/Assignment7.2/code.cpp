#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *root = NULL;

// Create new node
node* createNode(int x) {
    node* temp = new node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
node* insert(node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Count total nodes
int countNodes(node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Compute height of BST
int height(node* root) {
    if (root == NULL)
        return -1;  // height of empty tree = -1 (common definition)

    int left_h = height(root->left);
    int right_h = height(root->right);

    return 1 + max(left_h, right_h);
}

// Mirror Image
void mirror(node* root) {
    if (root == NULL)
        return;

    // Swap left and right children
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// Inorder Display
void inorder(node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    int choice_rdk, value_rdk;

    do {
        cout << "\n--- BST MENU ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Count Total Nodes\n";
        cout << "3. Compute Height\n";
        cout << "4. Mirror Image of BST\n";
        cout << "5. Display (Inorder)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {

            case 1:
                cout << "Enter value to insert: ";
                cin >> value_rdk;
                root = insert(root, value_rdk);
                break;

            case 2:
                cout << "Total Nodes = " << countNodes(root) << "\n";
                break;

            case 3:
                cout << "Height of BST = " << height(root) << "\n";
                break;

            case 4:
                mirror(root);
                cout << "Mirror image created successfully.\n";
                break;

            case 5:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << "\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice_rdk != 6);

    return 0;
}
