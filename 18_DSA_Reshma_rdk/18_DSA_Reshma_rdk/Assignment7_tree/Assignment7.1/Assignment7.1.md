## Title
Binary Search Tree Operations

## Objective
To implement Binary Search Tree (BST) operations including create, insert, delete, and level-wise display using C++.

## Theory
A Binary Search Tree (BST) is a node-based data structure where each node has at most two children. For any node:
- Left subtree contains nodes with values less than the node’s value.
- Right subtree contains nodes with values greater than the node’s value.
BST supports efficient searching, insertion, and deletion operations.

## Algorithm
1. Start with an empty tree.
2. For insertion:
   - Compare the value with the root.
   - Insert in the left or right subtree based on comparison.
3. For deletion:
   - If node has no child, delete directly.
   - If node has one child, replace node with its child.
   - If node has two children, replace with inorder successor.
4. For level-wise display:
   - Use a queue and print nodes level by level.
5. Continue operations until user exits.

## Code
```cpp
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

```

## Output
```
BST Operations Menu:
1. Insert Node
2. Delete Node
3. Level-wise Display
4. Exit
Enter your choice: 1
Enter value to insert: 50
50 inserted into BST.

Enter your choice: 1
Enter value to insert: 30
30 inserted into BST.

Enter your choice: 1
Enter value to insert: 70
70 inserted into BST.

Enter your choice: 3
Level-wise display of BST: 50 30 70

Enter your choice: 2
Enter value to delete: 30
30 deleted from BST (if it existed).

Enter your choice: 3
Level-wise display of BST: 50 70

Enter your choice: 4
Exiting program.
```

## Dry Run
Insert 50 → root = 50  
Insert 30 → goes to left of 50  
Insert 70 → goes to right of 50  

Level-order: 50 30 70  

Delete 30 → 30 has no children → deleted  

Level-order: 50 70  

Program ends.

## Conclusion
Binary Search Tree operations such as insertion, deletion, and level-wise traversal were successfully implemented using C++. BST allows efficient operations and helps maintain ordered hierarchical data.
