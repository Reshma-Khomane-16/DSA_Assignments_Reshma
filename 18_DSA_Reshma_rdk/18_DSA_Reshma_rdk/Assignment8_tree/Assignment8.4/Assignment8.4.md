# Product Inventory Management System Using Search Tree

## Title
Product Inventory Management System Using Search Tree

## Objective
To implement a product inventory system using a binary search tree where products are organized by their names, allowing insertion, inorder display, and listing of expired products.

## Theory
A binary search tree (BST) organizes data in a hierarchical structure where each left child contains values smaller than the parent and each right child contains values greater than the parent.  
Using a BST allows efficient insertion, searching, and traversal. In this program, products are stored in a BST sorted by product name, enabling alphabetical inventory display and structured traversal for identifying expired products.

## Algorithm

### Insert Product
1. If the tree is empty, create a new node.
2. Compare the product name with the root.
3. Insert into left subtree if smaller, else into right subtree.
4. Repeat until correct position is found.

### Inorder Traversal
1. Traverse left subtree.
2. Visit node.
3. Traverse right subtree.
4. Displays products in ascending order of name.

### List Expired Products (Preorder-like)
1. Check if current product is expired.
2. If expired, display details.
3. Traverse left subtree.
4. Traverse right subtree.

## Code
``#include <iostream>
#include <string>
using namespace std;

// Product structure as BST node
struct Product {
    string productCode;
    string name;
    double price;
    int quantity;
    string dateReceived;
    string expirationDate;
    Product* left;
    Product* right;
};

// Create new product node
Product* createProduct(string code, string name, double price, int quantity, string dateRec, string expDate) {
    Product* newProd = new Product;
    newProd->productCode = code;
    newProd->name = name;
    newProd->price = price;
    newProd->quantity = quantity;
    newProd->dateReceived = dateRec;
    newProd->expirationDate = expDate;
    newProd->left = newProd->right = nullptr;
    return newProd;
}

// Insert product into BST (sorted by name)
Product* insertProduct(Product* root, string code, string name, double price, int quantity, string dateRec, string expDate) {
    if (!root) return createProduct(code, name, price, quantity, dateRec, expDate);
    if (name < root->name)
        root->left = insertProduct(root->left, code, name, price, quantity, dateRec, expDate);
    else if (name > root->name)
        root->right = insertProduct(root->right, code, name, price, quantity, dateRec, expDate);
    return root;
}

// Inorder traversal (sorted by product name)
void displayInorder(Product* root) {
    if (root) {
        displayInorder(root->left);
        cout << "Code: " << root->productCode
             << ", Name: " << root->name
             << ", Price: " << root->price
             << ", Quantity: " << root->quantity
             << ", Received: " << root->dateReceived
             << ", Expiration: " << root->expirationDate << endl;
        displayInorder(root->right);
    }
}

// Preorder traversal to list expired items (prefix)
void listExpiredPreorder(Product* root, const string& currentDate) {
    if (root) {
        if (root->expirationDate < currentDate) { // Simple string comparison for dates YYYY-MM-DD
            cout << "Expired -> Code: " << root->productCode
                 << ", Name: " << root->name
                 << ", Price: " << root->price
                 << ", Quantity: " << root->quantity
                 << ", Expiration: " << root->expirationDate << endl;
        }
        listExpiredPreorder(root->left, currentDate);
        listExpiredPreorder(root->right, currentDate);
    }
}

// Main menu
int main() {
    Product* root = nullptr;
    int choice_rdk;
    string code_rdk, name_rdk, dateRec_rdk, expDate_rdk;
    double price_rdk;
    int quantity_rdk;
    string today_rdk;

    do {
        cout << "\n--- Product Inventory Menu ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Display All Products (Inorder)\n";
        cout << "3. List Expired Products (Preorder)\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;
        cin.ignore(); // clear input buffer

        switch (choice_rdk) {
            case 1:
                cout << "Enter Product Code: ";
                getline(cin, code_rdk);
                cout << "Enter Product Name: ";
                getline(cin, name_rdk);
                cout << "Enter Price: ";
                cin >> price_rdk;
                cout << "Enter Quantity: ";
                cin >> quantity_rdk;
                cin.ignore();
                cout << "Enter Date Received (YYYY-MM-DD): ";
                getline(cin, dateRec_rdk);
                cout << "Enter Expiration Date (YYYY-MM-DD): ";
                getline(cin, expDate_rdk);
                root = insertProduct(root, code_rdk, name_rdk, price_rdk, quantity_rdk, dateRec_rdk, expDate_rdk);
                break;

            case 2:
                cout << "\nAll Products (Inorder):\n";
                displayInorder(root);
                break;

            case 3:
                cout << "Enter Today's Date (YYYY-MM-DD): ";
                getline(cin, today_rdk);
                cout << "\nExpired Products (Preorder):\n";
                listExpiredPreorder(root, today_rdk);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_rdk != 4);

    return 0;
}

```

## Output
Enter number of products: 4
Enter ProductName Code Price Quantity DateReceived ExpiryDate: Pen 1 10 100pcs 10/12/25 10/12/26
Enter ProductName Code Price Quantity DateReceived ExpiryDate: pencil 2 10 100pcs 11/11/25 11/11/27
Enter ProductName Code Price Quantity DateReceived ExpiryDate: scale 3 15 200pcs 1/1/2025 12/12/27
Enter ProductName Code Price Quantity DateReceived ExpiryDate: sharpner 4 20 200pcs 2/2/2025 2/2/26

Inventory (Inorder Traversal):
10/12/26  pencil  2  10  100pcs  11/11/25
11/11/27  scale  3  15  200pcs  1/1/2025
12/12/27  sharpner  4  20  200pcs  2/2/2025
Pen  1  10  100  pcs  10/12/25

Enter today's date (YYYY-MM-DD): 
Expired Products (Preorder):
Pen  1  10/12/25
10/12/26  pencil  11/11/25
11/11/27  scale  1/1/2025
12/12/27  sharpner  2/2/2025
PS C:\Users\sneha\New folder\DSA.cpp> 

## Dry Run
Example: 
Insert products A, B, C.  
BST structure forms based on alphabetical order.  
Inorder prints A → B → C.  
Expired check compares expiry date strings with today's date.

## Conclusion
A BST-based inventory system allows efficient product organization by name, simplifies sorted display using inorder traversal, and supports structured retrieval of expired products via preorder traversal.
