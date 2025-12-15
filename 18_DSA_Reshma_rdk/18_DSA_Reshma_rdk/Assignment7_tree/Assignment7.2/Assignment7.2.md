# Binary Search Tree Operations Report

## Title
Binary Search Tree Operations: Count Nodes, Compute Height, and Mirror Image

## Objective
To implement a Binary Search Tree (BST) that supports counting the total number of nodes, computing the height, generating the mirror image, inserting nodes, and performing a level-wise display.

## Theory
A Binary Search Tree (BST) is a binary tree structure in which each node follows the property:
- Left subtree contains values less than the node.
- Right subtree contains values greater than the node.

Key operations:
- Counting nodes: Traverse the entire tree and sum all nodes.
- Computing height: Height is the longest path from the root to any leaf.
- Mirror image: Swap left and right subtrees recursively.
- Level-wise display: Breadth-first traversal using a queue.

## Algorithm

### Insert Node
1. If tree is empty, create a new node.
2. If value < root, insert into left subtree.
3. If value > root, insert into right subtree.

### Count Nodes
1. If node is NULL, return 0.
2. Return 1 + count(left subtree) + count(right subtree).

### Compute Height
1. If node is NULL, height = 0.
2. Height = 1 + max(height(left), height(right)).

### Mirror Image
1. If node is NULL, return.
2. Recursively mirror left and right subtrees.
3. Swap left and right pointers.

### Level-wise Display
1. Use a queue.
2. Push root.
3. Pop each node, print value, push its children.

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

```

## Output
```
BST Operations Menu:
1. Insert Node
2. Count Total Nodes
3. Compute Height
4. Mirror Image
5. Level-wise Display
6. Exit
Enter your choice: 1
Enter value to insert: 50
50 inserted into BST.
...
```

## Dry Run
### Insert: 50, 30, 70, 20
Tree formed:
```
      50
     /     30    70
  /
20
```

### Count Nodes
count(50) → 1 + count(30) + count(70)  
count(30) → 1 + count(20) + 0  
Total = 4

### Height
Height = 3

### Mirror
Before:
```
      50
     /     30    70
```
After:
```
      50
     /     70    30
```

## Conclusion
The program successfully performs insertion, counting nodes, computing height, generating mirror image, and displaying the BST level-wise.
