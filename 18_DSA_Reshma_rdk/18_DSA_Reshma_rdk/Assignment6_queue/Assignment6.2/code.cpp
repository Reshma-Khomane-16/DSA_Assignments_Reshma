/*Pizza parlour accepting maximum n orders. Orders are served on an FCFS basis. Order once placed
can’t be cancelled. Write C++ program to simulate the system using circular QUEUE.*/

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
