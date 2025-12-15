# Title

Binary Tree Non-Recursive Operations

# Objective

To create a binary tree and perform non-recursive inorder traversal, preorder traversal, count the number of leaf nodes, and generate the mirror image of the tree.

# Theory

A binary tree is a hierarchical data structure where each node has at most two children. Tree traversal can be done recursively or non-recursively using stacks. Non-recursive traversal eliminates function call overhead. Leaf nodes are nodes with no children. The mirror image of a binary tree is created by swapping left and right children of all nodes.

# Algorithm

## Inorder Traversal (Non-recursive)

1. Initialize an empty stack.
2. Traverse to the leftmost node.
3. Pop from stack, visit node, move to right subtree.
4. Repeat until stack is empty and current node is null.

## Preorder Traversal (Non-recursive)

1. Push root to stack.
2. Pop a node, visit it.
3. Push right child, then left child.
4. Continue until stack is empty.

## Count Leaf Nodes

1. If node is null, return 0.
2. If both children are null, return 1.
3. Recursively count leaf nodes in left and right subtrees.

## Mirror Image

1. For each node, swap left and right children.
2. Recursively mirror left and right subtrees.

# Code

```
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


```

# Output

Sample operations include insertion, non-recursive inorder traversal, preorder traversal, leaf node count, and mirror transformation.

# Dry Run

Example with inserted nodes: 50, 30, 70, 20, 40

* Inorder: 20 30 40 50 70
* Preorder: 50 30 20 40 70
* Leaf nodes: 3
* After mirror: Inorder becomes reversed structure

# Conclusion

Non-recursiv
