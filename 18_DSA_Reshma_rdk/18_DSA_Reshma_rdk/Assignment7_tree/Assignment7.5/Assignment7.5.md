# Title
Binary Tree Recursive Operations

# Objective
To create a binary tree and perform recursive inorder traversal, preorder traversal, count leaf nodes, and generate the mirror image of the tree.

# Theory
A binary tree is a hierarchical data structure in which each node has at most two children referred to as the left and right child. Recursive tree traversals allow systematic visiting of each node:
- Inorder: Left, Root, Right
- Preorder: Root, Left, Right  
A leaf node is one with no children. A mirror image swaps left and right subtrees recursively.

# Algorithm

## Insert Node (BST-based)
1. If tree is empty, create root.
2. If value < root, insert into left subtree.
3. Else insert into right subtree.

## Inorder Traversal (Recursive)
1. Traverse left subtree.
2. Visit root.
3. Traverse right subtree.

## Preorder Traversal (Recursive)
1. Visit root.
2. Traverse left subtree.
3. Traverse right subtree.

## Count Leaf Nodes
1. If node is null, return 0.
2. If node has no children, return 1.
3. Recursively count leaves of left and right subtrees.

## Mirror Image
1. Recursively mirror left and right subtrees.
2. Swap left and right child pointers.

# Code
```
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

```

# Output
Binary Tree Menu (Recursive):
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Count Leaf Nodes
5. Mirror Image
6. Exit
Enter your choice: 1
Enter value to insert: 4
4 inserted.

Binary Tree Menu (Recursive):
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Count Leaf Nodes
5. Mirror Image
6. Exit
Enter your choice: 2
Inorder Traversal: 4 

Binary Tree Menu (Recursive):
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Count Leaf Nodes
5. Mirror Image
6. Exit
Enter your choice: 3
Preorder Traversal: 4 

Binary Tree Menu (Recursive):
1. Insert Node
2. Inorder Traversal
3. Preorder Traversal
4. Count Leaf Nodes
5. Mirror Image
6. Exit
Enter your choice: 6
Exiting program.
PS C:\Users\sneha\New folder\DSA.cpp> 

# Dry Run
Example input sequence: Insert 4, Insert 5  
- Insert 4 → root = 4  
- Insert 5 → 5 > 4 → go right → insert  
- Inorder → 4 5  
- Preorder → 4 5  
- Leaf nodes → Only node 5 (1 leaf)  
- Mirror → 4 becomes root, 5 moves to left  

# Conclusion
Binary tree operations including traversal, leaf counting, and mirroring were successfully implemented using recursion.
