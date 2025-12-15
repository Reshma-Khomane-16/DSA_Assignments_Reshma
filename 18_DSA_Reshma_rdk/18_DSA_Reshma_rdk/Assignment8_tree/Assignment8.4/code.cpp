/*Write a program to implement a product inventory management system for a shop using a search tree
 data structure. Each product must store the following information:
●	Unique Product Code
●	Product Name
●	Price
●	Quantity in Stock
●	Date Received
●	Expiration Date
Implement the following operations:
1.	Insert a product into the tree ( organized by product name).
2.	Display all items in the inventory using inorder traversal.
3.	List expired items in prefix (preorder) order of their names.*/

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
