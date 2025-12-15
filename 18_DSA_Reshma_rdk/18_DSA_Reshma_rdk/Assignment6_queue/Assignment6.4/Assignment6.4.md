# Multiple Queues Using Array

## Title
Implementation of Multiple Queues Using Array in C++

## Objective
To implement two separate queues using arrays and perform operations such as insertion, deletion, and display.

## Theory
A queue is a linear data structure that follows the First-In-First-Out principle.  
In multiple queue implementation, two independent queues are maintained using separate arrays.  
Each queue has its own front and rear pointers to track insertion and deletion.

## Algorithm

### Enqueue
1. Check if the selected queue is full.
2. If not full, increment rear.
3. Insert the value at the rear position.
4. If the queue was empty, set front to 0.

### Dequeue
1. Check if the selected queue is empty.
2. If not empty, remove the element from the front.
3. Increment front pointer.

### Display
1. Check if the queue is empty.
2. If not, print all elements from front to rear.

## Code
```
#include <iostream>
using namespace std;

#define MAX_RDK 50  // Maximum elements in each queue

class MultiQueue {
private:
    string queue1_rdk[MAX_RDK], queue2_rdk[MAX_RDK];
    int front1_rdk, rear1_rdk, front2_rdk, rear2_rdk;

public:
    MultiQueue() {
        front1_rdk = rear1_rdk = -1;
        front2_rdk = rear2_rdk = -1;
    }

    // Check if queue1 is empty/full
    bool isEmpty1_rdk() { return front1_rdk == -1; }
    bool isFull1_rdk() { return rear1_rdk == MAX_RDK - 1; }

    // Check if queue2 is empty/full
    bool isEmpty2_rdk() { return front2_rdk == -1; }
    bool isFull2_rdk() { return rear2_rdk == MAX_RDK - 1; }

    // Add element to queue
    void addQueue_rdk(int qNo_rdk, string val_rdk) {
        if (qNo_rdk == 1) {
            if (isFull1_rdk()) {
                cout << "Queue 1 is full!\n";
                return;
            }
            if (isEmpty1_rdk()) front1_rdk = 0;
            rear1_rdk++;
            queue1_rdk[rear1_rdk] = val_rdk;
            cout << "Added \"" << val_rdk << "\" to Queue 1.\n";
        } else if (qNo_rdk == 2) {
            if (isFull2_rdk()) {
                cout << "Queue 2 is full!\n";
                return;
            }
            if (isEmpty2_rdk()) front2_rdk = 0;
            rear2_rdk++;
            queue2_rdk[rear2_rdk] = val_rdk;
            cout << "Added \"" << val_rdk << "\" to Queue 2.\n";
        } else {
            cout << "Invalid Queue number!\n";
        }
    }

    // Delete element from queue
    void deleteQueue_rdk(int qNo_rdk) {
        if (qNo_rdk == 1) {
            if (isEmpty1_rdk()) {
                cout << "Queue 1 is empty!\n";
                return;
            }
            cout << "Deleted \"" << queue1_rdk[front1_rdk] << "\" from Queue 1.\n";
            front1_rdk++;
            if (front1_rdk > rear1_rdk) front1_rdk = rear1_rdk = -1;
        } else if (qNo_rdk == 2) {
            if (isEmpty2_rdk()) {
                cout << "Queue 2 is empty!\n";
                return;
            }
            cout << "Deleted \"" << queue2_rdk[front2_rdk] << "\" from Queue 2.\n";
            front2_rdk++;
            if (front2_rdk > rear2_rdk) front2_rdk = rear2_rdk = -1;
        } else {
            cout << "Invalid Queue number!\n";
        }
    }

    // Display queue
    void displayQueue_rdk(int qNo_rdk) {
        if (qNo_rdk == 1) {
            if (isEmpty1_rdk()) {
                cout << "Queue 1 is empty!\n";
                return;
            }
            cout << "Queue 1 elements: ";
            for (int i_rdk = front1_rdk; i_rdk <= rear1_rdk; i_rdk++)
                cout << queue1_rdk[i_rdk] << " ";
            cout << endl;
        } else if (qNo_rdk == 2) {
            if (isEmpty2_rdk()) {
                cout << "Queue 2 is empty!\n";
                return;
            }
            cout << "Queue 2 elements: ";
            for (int i_rdk = front2_rdk; i_rdk <= rear2_rdk; i_rdk++)
                cout << queue2_rdk[i_rdk] << " ";
            cout << endl;
        } else {
            cout << "Invalid Queue number!\n";
        }
    }
};

int main() {
    MultiQueue mq_rdk;
    int choice_rdk, qNo_rdk;
    string val_rdk;

    do {
        cout << "\n=== MULTI QUEUE MENU ===\n";
        cout << "1. Add to Queue\n2. Delete from Queue\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter Queue number (1 or 2): ";
                cin >> qNo_rdk;
                cout << "Enter value to add: ";
                cin >> val_rdk;
                mq_rdk.addQueue_rdk(qNo_rdk, val_rdk);
                break;
            case 2:
                cout << "Enter Queue number (1 or 2): ";
                cin >> qNo_rdk;
                mq_rdk.deleteQueue_rdk(qNo_rdk);
                break;
            case 3:
                cout << "Enter Queue number (1 or 2): ";
                cin >> qNo_rdk;
                mq_rdk.displayQueue_rdk(qNo_rdk);
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
Menu:
1. Add to Queue
2. Delete from Queue
3. Display Queue
4. Exit
Enter your choice: 1
Enter queue number (1 or 2): 1
Enter value to add: 10
Added 10 to Queue 1.
```

## Dry Run
### Operation: Add 10 to Queue 1
front1 = -1, rear1 = -1  
front1 becomes 0  
rear1 becomes 0  
q1[0] = 10

### Operation: Add 20 to Queue 1
rear1 becomes 1  
q1[1] = 20

### Operation: Delete from Queue 1
front1 = 0, rear1 = 1  
Deleted element = q1[0]  
front1 becomes 1

## Conclusion
Two queues can be efficiently implemented using arrays by maintaining separate front and rear pointers. This allows independent queue operations without interference.