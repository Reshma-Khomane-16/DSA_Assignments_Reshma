# Title
Binary Search Tree: Find Minimum and Maximum

# Objective
To implement a Binary Search Tree (BST) and perform operations to find the minimum and maximum elements in the BST.

# Theory
A Binary Search Tree is a binary tree in which every node follows the property that the left child contains values smaller than the parent node and the right child contains values greater than the parent node.  
The minimum value in a BST is found by traversing left until the last left child is reached.  
The maximum value in a BST is found by traversing right until the last right child is reached.

# Algorithm
1. Start with an empty BST.
2. For insertion:
   - If the tree is empty, create the root node.
   - Otherwise, compare the value with the root and insert it in the left or right subtree appropriately.
3. To find the minimum:
   - Traverse left until the leftmost node is reached.
4. To find the maximum:
   - Traverse right until the rightmost node is reached.
5. Use inorder traversal to display the tree in sorted order.

# Code
```cpp
/*Write a Program to create a Binary Tree Search and Find Minimum/Maximum in BST*/ 

#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node* root = NULL;

// Create a new node
node* createNode(int x) {
    node* temp = new node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert node in BST
node* insert(node* root, int x) {
    if (root == NULL)
        return createNode(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Search a value in BST
bool search(node* root, int key) {
    if (root == NULL)
        return false;

    if (key == root->data)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Find Minimum in BST
int findMin(node* root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return -1;
    }

    while (root->left != NULL)
        root = root->left;

    return root->data;
}

// Find Maximum in BST
int findMax(node* root) {
    if (root == NULL) {
        cout << "Tree is empty!\n";
        return -1;
    }

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

// Inorder Traversal
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
        cout << "\n--- BST OPERATIONS MENU ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Value\n";
        cout << "3. Find Minimum\n";
        cout << "4. Find Maximum\n";
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
                cout << "Enter value to search: ";
                cin >> value_rdk;
                if (search(root, value_rdk))
                    cout << "Value FOUND in BST.\n";
                else
                    cout << "Value NOT found.\n";
                break;

            case 3:
                cout << "Minimum value = " << findMin(root) << "\n";
                break;

            case 4:
                cout << "Maximum value = " << findMax(root) << "\n";
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

```

# Output
Insertion: 50 30 70 20 40 60 80  
Minimum value: 20  
Maximum value: 80  
Inorder traversal: 20 30 40 50 60 70 80

# Dry Run
Insert 50 → becomes root  
Insert 30 → goes to left of 50  
Insert 70 → goes to right of 50  
Insert 20 → goes to left of 30  
Insert 40 → goes to right of 30  
Insert 60 → goes to left of 70  
Insert 80 → goes to right of 70  
Minimum is found by moving left: 50 → 30 → 20  
Maximum is found by moving right: 50 → 70 → 80  

# Conclusion
The program successfully creates a Binary Search Tree and performs operations to find the minimum and maximum values while demonstrating BST properties and traversal.
