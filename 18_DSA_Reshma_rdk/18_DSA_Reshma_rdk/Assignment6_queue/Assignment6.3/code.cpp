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
