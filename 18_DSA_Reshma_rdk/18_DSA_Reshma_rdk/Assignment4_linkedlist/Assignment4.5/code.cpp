/*Given a list, split it into two sublists — one for the front half, and one for the back half.
If the number of elements is odd, the extra element should go in the front list. So FrontBackSplit()
on the list {2, 3, 5, 7, 11} should yield the two lists {2, 3, 5} and {7, 11}. Getting this right
for all the cases is harder than it looks. You should check your solution against a few cases 
(length = 2, length = 3, length=4) to make sure that the list gets split correctly near the 
shortlist boundary conditions. If it works right for length=4, it probably works right for 
length=1000. You will probably need special case code to deal with the (length <2) cases.*/


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    // Insert at end
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Front–Back Split
    void frontBackSplit(LinkedList &frontList, LinkedList &backList) {
        if (head == NULL) {
            cout << "List has 0 elements, no split possible.\n";
            return;
        }
        if (head->next == NULL) {
            frontList.head = head;
            backList.head = NULL;
            return;
        }

        Node* slow = head;
        Node* fast = head->next;

        // Move fast by 2 and slow by 1
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // slow is at end of front half
        frontList.head = head;
        backList.head = slow->next;
        slow->next = NULL;   // break the original list
    }
};

int main() {
    LinkedList list;
    int choice_rdk, val_rdk;

    while (true) {
        cout << "\n===== FRONT-BACK SPLIT MENU =====\n";
        cout << "1. Insert Element\n";
        cout << "2. Display List\n";
        cout << "3. Split into Front and Back Lists\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter value: ";
                cin >> val_rdk;
                list.insertEnd(val_rdk);
                break;

            case 2:
                cout << "Current List: ";
                list.display();
                break;

            case 3: {
                LinkedList front_rdk, back_rdk;
                list.frontBackSplit(front_rdk, back_rdk);

                cout << "Front List: ";
                front_rdk.display();

                cout << "Back List: ";
                back_rdk.display();
                break;
            }

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
