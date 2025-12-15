# Call Center Queue System Using Linked List

## Title
Implementation of a Call Center Queue System Using Linked List in C++

## Objective
To simulate a call center where customer calls are handled on a first‑come, first‑served basis using a linked list‑based queue.

## Theory
A queue is a FIFO structure where the first element added is the first to be removed.  
Using a linked list to implement a queue allows dynamic memory allocation and avoids fixed‑size limitations.  
Each call is represented as a node containing customer details.  
Enqueue adds a call at the rear, and dequeue removes a call from the front.

## Algorithm

### Enqueue (Add Customer Call)
1. Create a new call node.
2. If the queue is empty, set both front and rear to the new node.
3. Otherwise, attach the new node to the rear and update rear.
4. Display confirmation.

### Dequeue (Handle Next Call)
1. If the queue is empty, display a waiting message.
2. Otherwise, remove the front node.
3. Move the front pointer to the next node.
4. If front becomes null, set rear to null.
5. Display details of the handled call.

### Display Calls
1. If queue is empty, display message.
2. Otherwise, traverse from front to rear printing call details.

## Code
```
#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    string customer_rdk;
    Node* next;
};

// Queue class using linked list
class CallCenterQueue {
private:
    Node* front_rdk;
    Node* rear_rdk;

public:
    CallCenterQueue() {
        front_rdk = rear_rdk = nullptr;
    }

    // Check if queue is empty
    bool isEmpty_rdk() {
        return front_rdk == nullptr;
    }

    // Enqueue customer
    void enqueue_rdk(string name_rdk) {
        Node* newNode_rdk = new Node;
        newNode_rdk->customer_rdk = name_rdk;
        newNode_rdk->next = nullptr;

        if (isEmpty_rdk()) {
            front_rdk = rear_rdk = newNode_rdk;
        } else {
            rear_rdk->next = newNode_rdk;
            rear_rdk = newNode_rdk;
        }
        cout << "Customer \"" << name_rdk << "\" added to the queue.\n";
    }

    // Dequeue customer
    void dequeue_rdk() {
        if (isEmpty_rdk()) {
            cout << "No calls in the queue. Waiting for customers...\n";
            return;
        }
        Node* temp_rdk = front_rdk;
        cout << "Assisting customer: " << front_rdk->customer_rdk << endl;
        front_rdk = front_rdk->next;
        delete temp_rdk;

        if (front_rdk == nullptr) rear_rdk = nullptr; // Queue becomes empty
    }

    // Display queue
    void display_rdk() {
        if (isEmpty_rdk()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp_rdk = front_rdk;
        cout << "Current Queue: ";
        while (temp_rdk != nullptr) {
            cout << temp_rdk->customer_rdk << " ";
            temp_rdk = temp_rdk->next;
        }
        cout << endl;
    }
};

int main() {
    CallCenterQueue cc_rdk;
    int choice_rdk;
    string name_rdk;

    do {
        cout << "\n=== CALL CENTER QUEUE MENU ===\n";
        cout << "1. Add Customer Call\n2. Assist Customer (Dequeue)\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter customer name: ";
                cin >> name_rdk;
                cc_rdk.enqueue_rdk(name_rdk);
                break;
            case 2:
                cc_rdk.dequeue_rdk();
                break;
            case 3:
                cc_rdk.display_rdk();
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

```

## Output
Sample output:
```
Call Center Menu:
1. Add Customer Call
2. Handle Next Call
3. Display Waiting Calls
4. Exit
Enter your choice: 1
Enter customer name: John
Enter call ID: 101
Call from John added to the queue.
```

## Dry Run
### Operation: Add Call (John, 101)
front = null, rear = null  
New node created  
front = new node  
rear = new node  

### Operation: Add Call (Anna, 102)
rear->next = new node  
rear = new node  

### Operation: Handle Next Call
front = John  
Remove John  
front moves to Anna  

## Conclusion
A linked list‑based queue efficiently manages dynamic call handling in a call center.  
It supports unlimited call entries subject to memory limits and ensures FIFO servicing.
