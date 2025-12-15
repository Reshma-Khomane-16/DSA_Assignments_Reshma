## Title
Stock Price Tracker Using Stack Implemented with Linked List

## Objective
To implement a stock price tracker that records, removes, and retrieves the latest stock price using a stack data structure built with a linked list.

## Theory
A stack is a linear data structure that follows the Last In First Out principle. Elements are inserted and deleted only from one end known as the top. A linked list allows dynamic memory allocation, eliminating size limitations. Using a linked list to implement a stack involves inserting and deleting nodes from the head since it represents the top of the stack.

## Algorithm
1. Initialize top as null.
2. For record(price):
   - Create a new node.
   - Set its next pointer to top.
   - Update top to the new node.
3. For remove():
   - If top is null, stack is empty.
   - Store top->price.
   - Move top to top->next.
   - Delete the old top node.
4. For latest():
   - If top is null, stack is empty.
   - Return top->price.
5. For isEmpty():
   - Return true if top is null, otherwise false.

## Code
```
#include <iostream>
using namespace std;

class Node {
public:
    int price_rdk;
    Node* next_rdk;

    Node(int val_rdk) {
        price_rdk = val_rdk;
        next_rdk = NULL;
    }
};

class Stack {
public:
    Node* top_rdk;

    Stack() {
        top_rdk = NULL;
    }

    // Record a new price (push)
    void record_rdk(int price_rdk) {
        Node* newNode_rdk = new Node(price_rdk);
        newNode_rdk->next_rdk = top_rdk;
        top_rdk = newNode_rdk;
        cout << "Price " << price_rdk << " recorded.\n";
    }

    // Remove most recent price (pop)
    void remove_rdk() {
        if (isEmpty_rdk()) {
            cout << "Stack is empty! No price to remove.\n";
            return;
        }
        Node* temp_rdk = top_rdk;
        cout << "Removed price: " << top_rdk->price_rdk << endl;
        top_rdk = top_rdk->next_rdk;
        delete temp_rdk;
    }

    // Latest price (peek)
    void latest_rdk() {
        if (isEmpty_rdk()) {
            cout << "Stack is empty! No latest price.\n";
            return;
        }
        cout << "Latest price: " << top_rdk->price_rdk << endl;
    }

    // Check if stack is empty
    bool isEmpty_rdk() {
        return top_rdk == NULL;
    }

    // Display all prices
    void display_rdk() {
        if (isEmpty_rdk()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack (Top -> Bottom): ";
        Node* temp_rdk = top_rdk;
        while (temp_rdk != NULL) {
            cout << temp_rdk->price_rdk << " ";
            temp_rdk = temp_rdk->next_rdk;
        }
        cout << endl;
    }
};

int main() {
    Stack stock_rdk;
    int choice_rdk, price_rdk;

    do {
        cout << "\n===== STOCK PRICE TRACKER (STACK) MENU =====\n";
        cout << "1. Record new price\n";
        cout << "2. Remove most recent price\n";
        cout << "3. View latest price\n";
        cout << "4. Display all recorded prices\n";
        cout << "5. Check if stack is empty\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter stock price: ";
                cin >> price_rdk;
                stock_rdk.record_rdk(price_rdk);
                break;

            case 2:
                stock_rdk.remove_rdk();
                break;

            case 3:
                stock_rdk.latest_rdk();
                break;

            case 4:
                stock_rdk.display_rdk();
                break;

            case 5:
                if (stock_rdk.isEmpty_rdk())
                    cout << "Stack is empty.\n";
                else
                    cout << "Stack is not empty.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice_rdk != 6);

    return 0;
}

```

## Output
Sample interaction:
```
1. Record Price
2. Remove Latest Price
3. View Latest Price
4. Check if Empty
5. Exit
Enter choice: 1
Enter price: 120

Enter choice: 1
Enter price: 150

Enter choice: 3
Latest Price: 150

Enter choice: 2
Removed Price: 150

Enter choice: 3
Latest Price: 120
```

## Dry Run
Input sequence: record(100), record(150), latest(), remove(), latest()

Step-by-step:
- record(100): top -> 100
- record(150): top -> 150 -> 100
- latest(): returns 150
- remove(): deletes 150, top -> 100
- latest(): returns 100

## Conclusion
The stack implemented using a linked list successfully records and manages stock prices dynamically. The operations efficiently follow the Last In First Out principle and demonstrate stack behavior effectively.
