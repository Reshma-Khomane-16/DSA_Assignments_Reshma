/*Implement Bubble sort using Doubly Linked List*/

#include <iostream>
using namespace std;

class Node {
public:
    int data_rdk;
    Node *prev_rdk, *next_rdk;

    Node(int val_rdk) {
        data_rdk = val_rdk;
        prev_rdk = NULL;
        next_rdk = NULL;
    }
};

class DoublyList {
public:
    Node *head_rdk;

    DoublyList() {
        head_rdk = NULL;
    }

    // Insert at end
    void insert_rdk(int val_rdk) {
        Node *newNode_rdk = new Node(val_rdk);

        if (head_rdk == NULL) {
            head_rdk = newNode_rdk;
            return;
        }

        Node *temp_rdk = head_rdk;
        while (temp_rdk->next_rdk != NULL)
            temp_rdk = temp_rdk->next_rdk;

        temp_rdk->next_rdk = newNode_rdk;
        newNode_rdk->prev_rdk = temp_rdk;
    }

    // Display list
    void display_rdk() {
        if (head_rdk == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node *temp_rdk = head_rdk;
        while (temp_rdk != NULL) {
            cout << temp_rdk->data_rdk;
            if (temp_rdk->next_rdk != NULL) cout << " <-> ";
            temp_rdk = temp_rdk->next_rdk;
        }
        cout << endl;
    }

    // Bubble Sort
    void bubbleSort_rdk() {
        if (head_rdk == NULL) {
            cout << "List is empty\n";
            return;
        }

        bool swapped_rdk;
        Node *ptr_rdk;
        Node *last_rdk = NULL;

        do {
            swapped_rdk = false;
            ptr_rdk = head_rdk;

            while (ptr_rdk->next_rdk != last_rdk) {
                if (ptr_rdk->data_rdk > ptr_rdk->next_rdk->data_rdk) {
                    // Swap values only
                    int temp_rdk = ptr_rdk->data_rdk;
                    ptr_rdk->data_rdk = ptr_rdk->next_rdk->data_rdk;
                    ptr_rdk->next_rdk->data_rdk = temp_rdk;

                    swapped_rdk = true;
                }
                ptr_rdk = ptr_rdk->next_rdk;
            }
            last_rdk = ptr_rdk;

        } while (swapped_rdk);

        cout << "List sorted using Bubble Sort.\n";
    }
};

int main() {
    DoublyList list_rdk;
    int choice_rdk, val_rdk;

    while (true) {
        cout << "\n===== DOUBLY LINKED LIST BUBBLE SORT MENU =====\n";
        cout << "1. Insert element\n";
        cout << "2. Display list\n";
        cout << "3. Sort list (Bubble Sort)\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {

            case 1:
                cout << "Enter value: ";
                cin >> val_rdk;
                list_rdk.insert_rdk(val_rdk);
                break;

            case 2:
                cout << "Current List: ";
                list_rdk.display_rdk();
                break;

            case 3:
                list_rdk.bubbleSort_rdk();
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
