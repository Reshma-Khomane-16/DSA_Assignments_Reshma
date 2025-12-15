## input

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int key;
    string name;
    Node* next;

    Node(int k, string n) {
        key = k;
        name = n;
        next = NULL;
    }
};

class HashTable {
    Node* table[10]; // fixed hash table of size 10

public:
    HashTable() {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }

    int hashFunc(int key) {
        return key % 10;
    }

    void insertRecord(int key, string name) {
        int index = hashFunc(key);
        Node* newNode = new Node(key, name);

        // Insert at beginning (simple chaining)
        newNode->next = table[index];
        table[index] = newNode;

        cout << "Record inserted successfully!\n";
    }

    void searchRecord(int key) {
        int index = hashFunc(key);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->key == key) {
                cout << "\nRecord Found:\n";
                cout << "Key: " << temp->key << ", Name: " << temp->name << "\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Record not found!\n";
    }

    void displayTable() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < 10; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];

            if (temp == NULL) {
                cout << "EMPTY\n";
                continue;
            }

            while (temp != NULL) {
                cout << " -> [" << temp->key << ", " << temp->name << "]";
                temp = temp->next;
            }
            cout << "\n";
        }
    }
};

int main() {
    int choice_rdk, key_rdk;
    string name_rdk;
    HashTable h_rdk;

    do {
        cout << "\n====== HASH TABLE (SEPARATE CHAINING) ======\n";
        cout << "1. Insert Record\n";
        cout << "2. Search Record\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            cout << "Enter key (int): ";
            cin >> key_rdk;
            cout << "Enter name: ";
            cin >> name_rdk;
            h_rdk.insertRecord(key_rdk, name_rdk);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key_rdk;
            h_rdk.searchRecord(key_rdk);
            break;

        case 3:
            h_rdk.displayTable();
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
