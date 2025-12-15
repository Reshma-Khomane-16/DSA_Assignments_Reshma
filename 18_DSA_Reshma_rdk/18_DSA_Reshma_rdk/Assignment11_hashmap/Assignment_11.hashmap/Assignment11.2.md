## input

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class HashTable {
    Node* table[10];   // array of linked lists

public:
    HashTable() {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    int hashFunction(int key) {
        return key % 10;
    }

    void insert(int key) {
        int index_rdk = hashFunction(key);

        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        // If bucket is empty
        if (table[index_rdk] == NULL) {
            table[index_rdk] = newNode;
        }
        else {
            // Insert at end of linked list
            Node* temp_rdk = table[index_rdk];
            while (temp_rdk->next != NULL) {
                temp_rdk = temp_rdk->next;
            }
            temp_rdk->next = newNode;
        }

        cout << "Inserted Successfully!\n";
    }

    void search(int key_rdk) {
        int index_rdk = hashFunction(key_rdk);

        Node* temp_rdk = table[index_rdk];
        while (temp_rdk != NULL) {
            if (temp_rdk->data == key_rdk) {
                cout << "Key found at bucket " << index_rdk << "\n";
                return;
            }
            temp_rdk = temp_rdk->next;
        }
        cout << "Key NOT Found!\n";
    }

    void removeKey(int key_rdk) {
        int index_rdk = hashFunction(key_rdk);

        Node* temp_rdk = table[index_rdk];
        Node* prev_rdk = NULL;

        while (temp_rdk != NULL) {
            if (temp_rdk->data == key_rdk) {
                if (prev_rdk == NULL) {
                    table[index_rdk] = temp_rdk->next;
                } else {
                    prev_rdk->next = temp_rdk->next;
                }
                delete temp_rdk;
                cout << "Key Deleted Successfully!\n";
                return;
            }
            prev_rdk = temp_rdk;
            temp_rdk = temp_rdk->next;
        }

        cout << "Key NOT Found!\n";
    }

    void display() {
        cout << "\n--- Hash Table (Separate Chaining) ---\n";
        for (int i = 0; i < 10; i++) {
            cout << i << ": ";
            Node* temp_rdk = table[i];
            while (temp_rdk != NULL) {
                cout << temp_rdk->data << " -> ";
                temp_rdk = temp_rdk->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashTable obj_rdk;
    int choice_rdk, key_rdk;

    do {
        cout << "\n--- Hash Table Menu (Separate Chaining) ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key_rdk;
            obj_rdk.insert(key_rdk);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key_rdk;
            obj_rdk.search(key_rdk);
            break;

        case 3:
            cout << "Enter key to delete: ";
            cin >> key_rdk;
            obj_rdk.removeKey(key_rdk);
            break;

        case 4:
            obj_rdk.display();
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
