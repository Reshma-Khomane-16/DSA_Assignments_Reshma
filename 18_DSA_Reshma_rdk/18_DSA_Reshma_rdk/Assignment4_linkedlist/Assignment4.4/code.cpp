/*WAP to create a doubly linked list and perform following operations on it.A) Insert (all cases)
 2. Delete (all cases).*/	

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyList {
public:
    Node *head;

    DoublyList() {
        head = NULL;
    }

    // Insert at beginning
    void insertBeg(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int val) {
        Node *newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at position
    void insertPos(int val, int pos) {
        if (pos == 1) {
            insertBeg(val);
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range!\n";
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    // Delete first
    void deleteBeg() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;
    }

    // Delete last
    void deleteEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
        delete temp;
    }

    // Delete at position
    void deletePos(int pos) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (pos == 1) {
            deleteBeg();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range!\n";
            return;
        }

        temp->prev->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyList list;
    int choice_rdk, val_rdk, pos_rdk;

    while (true) {
        cout << "\n==== DOUBLY LINKED LIST MENU ====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete at Position\n";
        cout << "7. Display List\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter value: ";
                cin >> val_rdk;
                list.insertBeg(val_rdk);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val_rdk;
                list.insertEnd(val_rdk);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> val_rdk;
                cout << "Enter position: ";
                cin >> pos_rdk;
                list.insertPos(val_rdk, pos_rdk);
                break;

            case 4:
                list.deleteBeg();
                break;

            case 5:
                list.deleteEnd();
                break;

            case 6:
                cout << "Enter position: ";
                cin >> pos_rdk;
                list.deletePos(pos_rdk);
                break;

            case 7:
                cout << "Current List: ";
                list.display();
                break;

            case 8:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
