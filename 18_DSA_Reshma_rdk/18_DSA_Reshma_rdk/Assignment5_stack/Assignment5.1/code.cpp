/*WAP to build a simple stock price tracker that keeps a history of daily stock prices entered by the user. To allow users to go back and view or remove the most recent price, implement a stack using a linked list to store these integer prices.
Implement the following operations:
1.	record(price) – Add a new stock price (an integer) to the stack.
2.	remove() – Remove and return the most recent price (top of the stack).
3.	latest() – Return the most recent stock price without removing it.
4.	isEmpty() – Check if there are no prices recorded.*/	


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
