## Title
Pizza Parlour Order Management System (Circular Queue)

## Objective

To simulate a pizza parlour system where a maximum of **n orders** can
be accepted and orders are served on a **First-Come, First-Served
(FCFS)** basis using a **circular queue**.

## Theory

A circular queue is a linear data structure in which the last position
is connected back to the first position, forming a circle.\
It efficiently utilizes memory by preventing unused spaces when elements
are deleted from the front.

Key features: - Fixed-size queue. - FIFO order processing. - Circular
indexing using modulo operations. - Automatic wrap-around when the end
of the queue is reached.

## Algorithm

1.  Initialize `front = -1` and `rear = -1`.
2.  Display menu with four options.
3.  If user selects:
    -   **Place Order:**
        -   Check if queue is full.\
        -   If not, insert order at `rear` and update indices
            circularly.
    -   **Serve Order:**
        -   Check if queue is empty.\
        -   Remove the order at `front` and update indices.
    -   **Display Orders:**
        -   Traverse from `front` to `rear` circularly and display
            pending orders.
    -   **Exit:** End the program.
4.  Repeat until Exit is selected.

## Code

``` cpp
#include <iostream>
using namespace std;

#define MAX_RDK 5   // Maximum orders

class CircularQueue {
private:
    string orders_rdk[MAX_RDK];
    int front_rdk, rear_rdk;

public:
    CircularQueue() {
        front_rdk = -1;
        rear_rdk = -1;
    }

    // Check if queue is full
    bool isFull_rdk() {
        return ((rear_rdk + 1) % MAX_RDK == front_rdk);
    }

    // Check if queue is empty
    bool isEmpty_rdk() {
        return (front_rdk == -1);
    }

    // Place a new order
    void placeOrder_rdk(string order_rdk) {
        if (isFull_rdk()) {
            cout << "Order queue is full! Cannot accept more orders.\n";
            return;
        }
        if (isEmpty_rdk()) front_rdk = 0;
        rear_rdk = (rear_rdk + 1) % MAX_RDK;
        orders_rdk[rear_rdk] = order_rdk;
        cout << "Order \"" << order_rdk << "\" placed successfully.\n";
    }

    // Serve order
    void serveOrder_rdk() {
        if (isEmpty_rdk()) {
            cout << "No orders to serve!\n";
            return;
        }
        cout << "Serving order: \"" << orders_rdk[front_rdk] << "\"\n";
        if (front_rdk == rear_rdk) { // Only one order left
            front_rdk = rear_rdk = -1;
        } else {
            front_rdk = (front_rdk + 1) % MAX_RDK;
        }
    }

    // Display current orders
    void displayOrders_rdk() {
        if (isEmpty_rdk()) {
            cout << "No orders in the queue.\n";
            return;
        }
        cout << "Current orders: ";
        int i_rdk = front_rdk;
        while (true) {
            cout << orders_rdk[i_rdk] << " ";
            if (i_rdk == rear_rdk) break;
            i_rdk = (i_rdk + 1) % MAX_RDK;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue pizza_rdk;
    int choice_rdk;
    string order_rdk;

    do {
        cout << "\n=== PIZZA PARLOUR MENU ===\n";
        cout << "1. Place Order\n2. Serve Order\n3. Display Orders\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter pizza order: ";
                cin >> order_rdk;
                pizza_rdk.placeOrder_rdk(order_rdk);
                break;
            case 2:
                pizza_rdk.serveOrder_rdk();
                break;
            case 3:
                pizza_rdk.displayOrders_rdk();
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

## Sample Output

    Pizza Parlour Menu:
    1. Place Order
    2. Serve Order
    3. Display Pending Orders
    4. Exit
    Enter your choice: 1
    Enter Order ID: 101
    Order 101 placed.

    Enter your choice: 1
    Enter Order ID: 102
    Order 102 placed.

    Enter your choice: 1
    Enter Order ID: 103
    Order 103 placed.

    Enter your choice: 3
    Pending orders: 101 102 103

    Enter your choice: 2
    Order 101 served.

    Enter your choice: 3
    Pending orders: 102 103

    Enter your choice: 4
    Exiting system.

## Dry Run

### Input Sequence

1.  Place order: 101\
2.  Place order: 102\
3.  Place order: 103\
4.  Display orders\
5.  Serve order\
6.  Display orders

### Execution

-   After order 101 → Queue: \[101\]\
-   After order 102 → Queue: \[101, 102\]\
-   After order 103 → Queue: \[101, 102, 103\]\
-   Serve order → Removes 101\
-   Remaining → \[102, 103\]

## Conclusion

This program efficiently simulates a pizza parlour order system using a
circular queue. It ensures proper memory utilization and processes
orders in FCFS order while maintaining a fixed maximum capacity.