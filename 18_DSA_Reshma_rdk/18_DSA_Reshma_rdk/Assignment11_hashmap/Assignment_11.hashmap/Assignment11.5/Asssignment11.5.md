## input

#include <iostream>
#include <string>
using namespace std;

#define SIZE 10   // Hash table size

class Faculty {
public:
    int id;
    string name;
    string dept;

    Faculty() {
        id = -1;  // -1 means EMPTY
        name = "";
        dept = "";
    }
};

class HashTable {
public:
    Faculty table[SIZE];

    int hashFunc(int key) {
        return key % SIZE;
    }

    void insertFaculty(int id, string name, string dept) {
        int index = hashFunc(id);

        // Linear probing
        for (int i = 0; i < SIZE; i++) {
            int newIndex = (index + i) % SIZE;

            if (table[newIndex].id == -1) { // empty slot
                table[newIndex].id = id;
                table[newIndex].name = name;
                table[newIndex].dept = dept;

                cout << "Faculty inserted successfully!\n";
                return;
            }
        }

        cout << "Hash table full! Cannot insert.\n";
    }

    void searchFaculty(int id) {
        int index = hashFunc(id);

        for (int i = 0; i < SIZE; i++) {
            int newIndex = (index + i) % SIZE;

            if (table[newIndex].id == id) {
                cout << "\nFaculty Found:\n";
                cout << "ID: " << table[newIndex].id << "\n";
                cout << "Name: " << table[newIndex].name << "\n";
                cout << "Department: " << table[newIndex].dept << "\n";
                return;
            }
        }

        cout << "Faculty not found!\n";
    }

    void displayTable() {
        cout << "\n------ FACULTY HASH TABLE ------\n";
        for (int i = 0; i < SIZE; i++) {
            if (table[i].id != -1) {
                cout << "[" << i << "] "
                     << table[i].id << " - "
                     << table[i].name << " - "
                     << table[i].dept << "\n";
            } else {
                cout << "[" << i << "] EMPTY\n";
            }
        }
    }
};

int main() {
    int choice_rdk, id_rdk;
    string name_rdk, dept_rdk;

    HashTable h_rdk;

    do {
        cout << "\n=========== FACULTY DATABASE ===========\n";
        cout << "1. Insert Faculty\n";
        cout << "2. Search Faculty\n";
        cout << "3. Display Hash Table\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            cout << "Enter Faculty ID: ";
            cin >> id_rdk;
            cout << "Enter Name: ";
            cin >> name_rdk;
            cout << "Enter Department: ";
            cin >> dept_rdk;
            h_rdk.insertFaculty(id_rdk, name_rdk, dept_rdk);
            break;

        case 2:
            cout << "Enter Faculty ID to search: ";
            cin >> id_rdk;
            h_rdk.searchFaculty(id_rdk);
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
