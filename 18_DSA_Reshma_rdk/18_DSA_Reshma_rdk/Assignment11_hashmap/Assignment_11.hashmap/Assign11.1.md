## input

#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable 
{
    int arr[SIZE];

public:
    HashTable()
     {
        for (int i = 0; i < SIZE; i++)
            arr[i] = -1;
    }

    int hashFunction(int key) 
    {
        return key % SIZE;
    }

    void insert(int key)
     {
        int index_rdk =  hashFunction(key);

        int start_rdk = index_rdk;  // to detect full table
        while (arr[index_rdk] != -1) {
            index_rdk = (index_rdk + 1) % SIZE;
            if (index_rdk == start_rdk) 
            {
                cout << "Hash Table is FULL!\n";
                return;
            }
        }
        arr[index_rdk] = key;
        cout << "Inserted Successfully!\n";
    }

    void search(int key) 
    {
        int index_rdk = hashFunction(key);

        int start_rdk = index_rdk;
        while (arr[index_rdk] != -1)
         {
            if (arr[index_rdk] == key) 
            {
                cout << "Key Found at index: " << index_rdk << "\n";
                return;
            }
            index_rdk = (index_rdk + 1) % SIZE;
            if (index_rdk == start_rdk) break;
        }

        cout << "Key NOT Found!\n";
    }

    void removeKey(int key)
     {
        int index_rdk = hashFunction(key);

        int start_rdk = index_rdk;
        while (arr[index_rdk] != -1) 
        {
            if (arr[index_rdk] == key) 
            {
                arr[index_rdk] = -1;
                cout << "Key Deleted Successfully!\n";
                return;
            }
            index_rdk = (index_rdk + 1) % SIZE;
            if (index_rdk == start_rdk) break;
        }

        cout << "Key NOT Found!\n";
    }

    void display() 
    {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": " << arr[i] << "\n";
        }
    }
};

int main() 
{
    HashTable obj_rdk;
    int choice_rdk, key_rdk;

    do {
        cout << "\n--- Hash Table Menu ---\n";
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
            cout << "Exiting...!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice_rdk != 5);

    return 0;
}
