## Title
Passenger Ticket Counter Queue System

## Objective

To simulate a ticket counter system where passengers are added to a
queue and served in a **First-Come, First-Served (FCFS)** manner using a
standard queue.

## Theory

A queue is a linear data structure that follows the FIFO
(First-In-First-Out) principle.\
It is widely used in real-world applications such as ticket counters,
printer queues, and customer service systems.

In this program: - Each passenger has a name and ticket number. - A
queue stores incoming passengers. - Only the passenger at the front can
be served or removed.

## Algorithm

1.  Initialize an empty queue.
2.  Display menu options.
3.  Based on the user's choice:
    -   **Add Passenger**: Input name and ticket number, then push into
        the queue.
    -   **Display Front Passenger**: Show the passenger at the front
        without removing.
    -   **Remove Passenger**: Remove the front passenger from the queue.
    -   **Exit**: Quit the program.
4.  Repeat steps until the user selects Exit.
5.  Display remaining passengers in the queue.
6.  End program.

## Code

``` cpp
#include <iostream>
using namespace std;

#define MAX_RDK 100  // Maximum passengers

class PassengerQueue {
private:
    string queue_rdk[MAX_RDK];
    int front_rdk, rear_rdk;

public:
    PassengerQueue() {
        front_rdk = -1;
        rear_rdk = -1;
    }

    bool isEmpty_rdk() {
        return front_rdk == -1;
    }

    bool isFull_rdk() {
        return rear_rdk == MAX_RDK - 1;
    }

    // Insert passenger at rear
    void insertPassenger_rdk(string name_rdk) {
        if (isFull_rdk()) {
            cout << "Queue is full! Cannot add passenger.\n";
            return;
        }
        if (isEmpty_rdk()) front_rdk = 0;
        rear_rdk++;
        queue_rdk[rear_rdk] = name_rdk;
        cout << "Passenger " << name_rdk << " added to the queue.\n";
    }

    // Remove passenger from front
    void removePassenger_rdk() {
        if (isEmpty_rdk()) {
            cout << "Queue is empty! No passenger to remove.\n";
            return;
        }
        cout << "Passenger " << queue_rdk[front_rdk] << " removed from the queue.\n";
        front_rdk++;
        if (front_rdk > rear_rdk) { // Queue becomes empty
            front_rdk = rear_rdk = -1;
        }
    }

    // Display passenger at front
    void displayFront_rdk() {
        if (isEmpty_rdk()) {
            cout << "Queue is empty! No passenger at front.\n";
            return;
        }
        cout << "Passenger at front: " << queue_rdk[front_rdk] << endl;
    }

    // Display number of passengers
    void displayCount_rdk() {
        if (isEmpty_rdk()) {
            cout << "Number of passengers left: 0\n";
        } else {
            cout << "Number of passengers left: " << (rear_rdk - front_rdk + 1) << endl;
        }
    }
};

int main() {
    PassengerQueue pq_rdk;
    int choice_rdk;
    string name_rdk;

    do {
        cout << "\n=== TICKET AGENT QUEUE MENU ===\n";
        cout << "1. Insert Passenger\n2. Remove Passenger\n3. Display Front Passenger\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter passenger name: ";
                cin >> name_rdk;
                pq_rdk.insertPassenger_rdk(name_rdk);
                break;
            case 2:
                pq_rdk.removePassenger_rdk();
                break;
            case 3:
                pq_rdk.displayFront_rdk();
                break;
            case 4:
                pq_rdk.displayCount_rdk();
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice_rdk != 4);

    return 0;
}

```

## Sample Output

    Ticket Counter Menu:
    1. Add new passenger
    2. Display front passenger
    3. Remove front passenger
    4. Exit
    Enter your choice: 1
    Enter passenger name: Amit
    Enter ticket number: 201
    Passenger Amit added to the queue.

    Enter your choice: 1
    Enter passenger name: Neha
    Enter ticket number: 202
    Passenger Neha added to the queue.

    Enter your choice: 2
    Front passenger: Amit, Ticket No: 201

    Enter your choice: 3
    Passenger Amit removed from the queue.

    Enter your choice: 3
    Passenger Neha removed from the queue.

    Enter your choice: 4
    Exiting system.
    Passengers left in the queue: 0

## Dry Run

### Input Sequence

1.  Add passenger: Amit, 201\
2.  Add passenger: Neha, 202\
3.  Display front passenger\
4.  Remove passenger\
5.  Remove passenger\
6.  Exit

### Execution

-   After Amit added → Queue: \[Amit\]\
-   After Neha added → Queue: \[Amit, Neha\]\
-   Display front → Amit\
-   Remove → Queue becomes \[Neha\]\
-   Remove → Queue becomes empty

## Conclusion

This program demonstrates the use of a queue to manage passengers at a
ticket counter. It successfully models FCFS behavior and provides
operations to add, view, and remove passengers.