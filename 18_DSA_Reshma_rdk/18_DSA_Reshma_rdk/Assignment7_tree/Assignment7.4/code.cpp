/*Write a Program to create a Binary Tree and perform following Nonrecursive operations on it.
 a.Inorder Traversal b. Preorder Traversal c. Display Number of Leaf Nodes d. Mirror Image*/
#include <iostream>
#include <stack>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* root = NULL;

// Create Node
node* createNode(int x) {
    node* temp = new node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert nodes manually in a binary tree (NOT BST)
node* insert(node* root) {
    int x;
    cout << "Enter data for node: ";
    cin >> x;

    if (root == NULL)
        return createNode(x);

    cout << "Insert left child of " << root->data << " ? (1/0): ";
    int ch;
    cin >> ch;
    if (ch == 1)
        root->left = insert(root->left);

    cout << "Insert right child of " << root->data << " ? (1/0): ";
    cin >> ch;
    if (ch == 1)
        root->right = insert(root->right);

    return root;
}

// Nonrecursive Inorder Traversal
void inorderNR(node* root) {
    stack<node*> st;
    node* curr = root;

    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

// Nonrecursive Preorder Traversal
void preorderNR(node* root) {
    if (root == NULL) return;

    stack<node*> st;
    st.push(root);

    while (!st.empty()) {
        node* temp = st.top();
        st.pop();
        cout << temp->data << " ";

        if (temp->right != NULL)
            st.push(temp->right);
        if (temp->left != NULL)
            st.push(temp->left);
    }
}

// Count leaf nodes
int leafCount(node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;

    return leafCount(root->left) + leafCount(root->right);
}

// Mirror Image
void mirror(node* root) {
    if (root == NULL) return;

    stack<node*> st;
    st.push(root);

    while (!st.empty()) {
        node* temp = st.top();
        st.pop();

        // Swap children
        node* t = temp->left;
        temp->left = temp->right;
        temp->right = t;

        if (temp->left)
            st.push(temp->left);
        if (temp->right)
            st.push(temp->right);
    }
}

int main() {

    int choice_rdk;

    do {
        cout << "\n--- BINARY TREE NON-RECURSIVE OPERATIONS ---\n";
        cout << "1. Create Binary Tree\n";
        cout << "2. Inorder Traversal (Nonrecursive)\n";
        cout << "3. Preorder Traversal (Nonrecursive)\n";
        cout << "4. Count Leaf Nodes\n";
        cout << "5. Mirror Image\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {

            case 1:
                root = insert(root);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorderNR(root);
                cout << "\n";
                break;

            case 3:
                cout << "Preorder Traversal: ";
                preorderNR(root);
                cout << "\n";
                break;

            case 4:
                cout << "Total Leaf Nodes: " << leafCount(root) << "\n";
                break;

            case 5:
                mirror(root);
                cout << "Mirror Image created.\n";
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
