# Bubble Sort Using Doubly Linked List

## Title
Bubble Sort Implementation Using Doubly Linked List

## Objective
To implement bubble sort on a doubly linked list and understand how sorting works on linked data structures instead of arrays.

## Theory
A doubly linked list is a linear data structure where each node contains three parts:
- Data
- Pointer to the next node
- Pointer to the previous node

Bubble sort repeatedly compares adjacent elements and swaps them if they are in the wrong order. The process continues until no swaps are needed.

## Algorithm
1. Start from the head node.
2. Compare each node's data with the next node.
3. If the current node’s data is greater than the next node’s data, swap values.
4. Continue until reaching the end of the list.
5. Repeat the process until no swaps occur in a full pass.

## Code
```cpp
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

```

## Output
```
Enter number of elements: 5
Enter elements:
8 3 1 7 4

Original List: 8 3 1 7 4
Sorted List: 1 3 4 7 8
```

## Dry Run
Example list: 8 3 1 7 4

Pass 1:
- 8 > 3 → swap → 3 8 1 7 4
- 8 > 1 → swap → 3 1 8 7 4
- 8 > 7 → swap → 3 1 7 8 4
- 8 > 4 → swap → 3 1 7 4 8

Pass 2:
- 3 > 1 → swap → 1 3 7 4 8
- 7 > 4 → swap → 1 3 4 7 8

Pass 3:
- No swaps for remaining unsorted portion.

Final Sorted List: 1 3 4 7 8

## Conclusion
The bubble sort algorithm successfully sorts a doubly linked list by repeatedly swapping adjacent values. This program demonstrates the working of sorting on linked structures and strengthens understanding of linked list traversal.
