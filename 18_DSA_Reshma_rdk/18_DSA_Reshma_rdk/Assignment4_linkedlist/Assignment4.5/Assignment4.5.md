## Title 
Front-Back Split in Singly Linked List

## Objective

To split a singly linked list into two sublists: the front half and the
back half.\
If the number of elements is odd, the extra element goes into the front
list.

## Theory

The FrontBackSplit operation divides a list into two halves.\
This is achieved using the slow and fast pointer technique: - Slow
pointer moves one node at a time. - Fast pointer moves two nodes at a
time. When fast reaches the end, slow is at the midpoint.

For odd-length lists, the front list gets the extra element.\
Special cases include lists with 0 or 1 element.

## Algorithm

1.  If the list is empty, both front and back are NULL.
2.  If there is only one node, front gets the node and back is NULL.
3.  Use slow and fast pointers to find the midpoint.
4.  Split list at the midpoint.
5.  Assign front and back references.

## Code

``` cpp
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

```

## Sample Output

    Enter number of elements: 5
    Enter elements: 2 3 5 7 11

    Original List: 2 3 5 7 11
    Front List: 2 3 5
    Back List: 7 11

## Dry Run (Example for List: 2 3 5 7 11)

Slow = 2\
Fast = 3

Iteration 1:\
Slow = 3\
Fast = 7

Iteration 2:\
Slow = 5\
Fast = NULL

Split at node 5

Front = 2 3 5\
Back = 7 11

## Conclusion

The program successfully splits a singly linked list into two balanced
halves using the efficient slow-fast pointer approach. It correctly
handles edge cases and uneven list lengths.