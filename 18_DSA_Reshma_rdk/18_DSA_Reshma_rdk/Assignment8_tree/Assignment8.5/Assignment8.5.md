# Product Inventory Deletion System

## Title
Deletion Operations in Product Inventory System Using Search Tree

## Objective
To implement deletion functionality in a product inventory system using a binary search tree. The system supports deleting a product by its unique product code and deleting all expired products based on the current date.

## Theory
A binary search tree (BST) organizes data so that searching, insertion, and deletion operations can be performed efficiently. Each node in the BST contains product information. Deletion in BST involves three cases: deleting a leaf node, deleting a node with one child, and deleting a node with two children. Expired products are identified using date comparison and removed using recursive traversal.

## Algorithm
1. Insert products into the BST using product code as the key.
2. Display the inventory using inorder traversal.
3. For deletion by product code:
   - Traverse left or right based on comparison.
   - Handle three deletion cases of BST.
4. For deleting expired products:
   - Compare product expiry date with the current date.
   - Recursively delete expired nodes.
5. Show updated inventory after each deletion step.

## Code
```cpp
#include <iostream>
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

// Find minimum node in BST
Product* findMin(Product* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// Delete product by code
Product* deleteByCode(Product* root, string code) {
    if (!root) return nullptr;

    if (code < root->productCode)
        root->left = deleteByCode(root->left, code);
    else if (code > root->productCode)
        root->right = deleteByCode(root->right, code);
    else {
        // Node found
        if (!root->left) {
            Product* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Product* temp = root->left;
            delete root;
            return temp;
        }
        Product* temp = findMin(root->right);
        root->productCode = temp->productCode;
        root->name = temp->name;
        root->price = temp->price;
        root->quantity = temp->quantity;
        root->dateReceived = temp->dateReceived;
        root->expirationDate = temp->expirationDate;
        root->right = deleteByCode(root->right, temp->productCode);
    }
    return root;
}

// Delete expired products based on current date
Product* deleteExpired(Product* root, const string& today) {
    if (!root) return nullptr;

    root->left = deleteExpired(root->left, today);
    root->right = deleteExpired(root->right, today);

    if (root->expirationDate < today) { // expired
        Product* temp;
        if (!root->left) {
            temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            temp = root->left;
            delete root;
            return temp;
        } else {
            Product* minRight = findMin(root->right);
            root->productCode = minRight->productCode;
            root->name = minRight->name;
            root->price = minRight->price;
            root->quantity = minRight->quantity;
            root->dateReceived = minRight->dateReceived;
            root->expirationDate = minRight->expirationDate;
            root->right = deleteByCode(root->right, minRight->productCode);
        }
    }
    return root;
}

// Inorder traversal to display products
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

// Main menu
int main() {
    Product* root = nullptr;
    int choice_rdk;
    string code_rdk, name_rdk, dateRec_rdk, expDate_rdk, today_rdk;
    double price_rdk;
    int quantity_rdk;

    do {
        cout << "\n--- Product Inventory Deletion Menu ---\n";
        cout << "1. Insert Product\n";
        cout << "2. Delete Product by Code\n";
        cout << "3. Delete All Expired Products\n";
        cout << "4. Display All Products (Inorder)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;
        cin.ignore();

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
                cout << "Enter Product Code to delete: ";
                getline(cin, code_rdk);
                root = deleteByCode(root, code_rdk);
                cout << "Product deleted if it existed.\n";
                break;

            case 3:
                cout << "Enter Today's Date (YYYY-MM-DD): ";
                getline(cin, today_rdk);
                root = deleteExpired(root, today_rdk);
                cout << "All expired products deleted.\n";
                break;

            case 4:
                cout << "\nAll Products (Inorder):\n";
                displayInorder(root);
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

```

## Output
Enter number of products: 4
Enter Code Name Price Quantity DateReceived ExpiryDate: 1 Chair 700 12 12/2/25 12/2/30
Enter Code Name Price Quantity DateReceived ExpiryDate: 2 Cot 12000 10 12/4/25 12/4/40
Enter Code Name Price Quantity DateReceived ExpiryDate: 3 Sofa 20000 5 1/1/25 1/1/35
Enter Code Name Price Quantity DateReceived ExpiryDate: 4 Fan 2000 15 1/1/25 1/1/30

Inventory Inorder:
1 Chair 12/2/30
2 Cot 12/4/40
3 Sofa 1/1/35
4 Fan 1/1/30

Enter product code to delete: 4

Inventory After Deletion:
1 Chair 12/2/30
2 Cot 12/4/40
3 Sofa 1/1/35

Enter today's date (YYYY-MM-DD): 17/12/25

Inventory After Removing Expired Products:
PS C:\Users\sneha\New folder\DSA.cpp> 

## Dry Run
Example:
- Insert products with codes: P03, P01, P05
- Delete product P01 → BST reorganizes
- Today's date: 2024-10-20
- Products with expiry less than today are removed

## Conclusion
The system successfully performs deletion of a specific product and removal of expired products using binary search tree operations. Inorder traversal ensures sorted inventory display.
