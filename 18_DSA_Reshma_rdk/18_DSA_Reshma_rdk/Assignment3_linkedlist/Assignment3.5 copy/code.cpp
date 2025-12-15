/*Write a C++ program to store a binary number using a doubly linked list. Implement the following 
functions:
a) Calculate and display the 1’s complement and 2’s complement of the stored binary number.
b) Perform addition of two binary numbers represented using doubly linked lists and display the 
result.*/
	
#include <iostream>
using namespace std;

class Node {
public:
    int bit;
    Node *prev, *next;

    Node(int b) {
        bit = b;
        prev = next = NULL;
    }
};

class BinaryDLL {
public:
    Node *head, *tail;

    BinaryDLL() {
        head = tail = NULL;
    }

    void insertBit(int b) {
        Node *n = new Node(b);
        if (head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->bit;
            temp = temp->next;
        }
        cout << endl;
    }

    // 1's complement
    void onesComplement() {
        Node *temp = head;
        while (temp != NULL) {
            temp->bit = (temp->bit == 0) ? 1 : 0;
            temp = temp->next;
        }
    }

    // 2's complement
    void twosComplement() {
        onesComplement();
        int carry = 1;
        Node *temp = tail;

        while (temp != NULL && carry == 1) {
            if (temp->bit == 0) {
                temp->bit = 1;
                carry = 0;
            } else {
                temp->bit = 0;
            }
            temp = temp->prev;
        }
    }

    // Add two binary DLLs
    static BinaryDLL add(BinaryDLL &A, BinaryDLL &B) {
        BinaryDLL result;
        Node *p = A.tail;
        Node *q = B.tail;

        int carry = 0;

        while (p != NULL || q != NULL || carry == 1) {
            int x = (p ? p->bit : 0);
            int y = (q ? q->bit : 0);
            int sum = x + y + carry;

            result.insertFront(sum % 2);
            carry = sum / 2;

            if (p) p = p->prev;
            if (q) q = q->prev;
        }

        return result;
    }

    void insertFront(int b) {
        Node *n = new Node(b);
        if (head == NULL) {
            head = tail = n;
        } else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }
};

int main() {

    BinaryDLL num1_rdk, num2_rdk, result_rdk;
    int choice_rdk;
    int bit_rdk, n_rdk;

    while (true) {
        cout << "\n==== BINARY DLL MENU ====\n";
        cout << "1. Enter Binary Number 1\n";
        cout << "2. Enter Binary Number 2\n";
        cout << "3. Display Numbers\n";
        cout << "4. 1's Complement of Number 1\n";
        cout << "5. 2's Complement of Number 1\n";
        cout << "6. Add Number 1 and Number 2\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {

        case 1:
            cout << "Enter number of bits: ";
            cin >> n_rdk;

            cout << "Enter bits (0/1):\n";
            for (int i = 0; i < n_rdk; i++) {
                cin >> bit_rdk;
                num1_rdk.insertBit(bit_rdk);
            }
            break;

        case 2:
            cout << "Enter number of bits: ";
            cin >> n_rdk;

            cout << "Enter bits (0/1):\n";
            for (int i = 0; i < n_rdk; i++) {
                cin >> bit_rdk;
                num2_rdk.insertBit(bit_rdk);
            }
            break;

        case 3:
            cout << "Number 1: ";
            num1_rdk.display();
            cout << "Number 2: ";
            num2_rdk.display();
            break;

        case 4:
            cout << "1's Complement of Number 1: ";
            num1_rdk.onesComplement();
            num1_rdk.display();
            break;

        case 5:
            cout << "2's Complement of Number 1: ";
            num1_rdk.twosComplement();
            num1_rdk.display();
            break;

        case 6:
            cout << "Addition Result: ";
            result_rdk = BinaryDLL::add(num1_rdk, num2_rdk);
            result_rdk.display();
            break;

        case 7:
            return 0;

        default:
            cout << "Invalid choice!\n";
        }
    }
}
