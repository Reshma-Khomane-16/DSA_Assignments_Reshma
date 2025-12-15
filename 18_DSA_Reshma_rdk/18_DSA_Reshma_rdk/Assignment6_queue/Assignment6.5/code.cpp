/*In a call center, customer calls are handled on a first-come, first-served basis. Implement a queue system using Linked list where:
●	Each customer call is enqueued as it arrives.
●	Customer service agents dequeue calls to assist customers.
●	If there are no calls, the system waits.*/
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
