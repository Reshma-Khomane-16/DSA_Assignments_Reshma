# Assignment 5 - Binary Number Operations Using Doubly Linked List

## Title  
Binary Number Operations Using Doubly Linked List in C++

## Objective  
To implement a C++ program that stores a binary number using a doubly linked list and performs the following operations:  
- 1’s complement  
- 2’s complement  
- Addition of two binary numbers

## Theory  
A doubly linked list is a linear data structure where each node has:  
- `data` – stores the bit (0 or 1)  
- `prev` – pointer to the previous node  
- `next` – pointer to the next node  

This structure helps in performing binary operations from right to left (least significant bit first).

### 1’s Complement  
Flip every bit:  
- 0 becomes 1  
- 1 becomes 0  

### 2’s Complement  
Steps:  
1. Find 1’s complement  
2. Add 1 to the result  

### Binary Addition  
Addition is performed from last node (LSB) to first using carry-forward logic.

---

## Algorithm  

### **Insert Bit**
1. Create a new node  
2. If list empty, set head and tail  
3. Else, append at tail  

### **1’s Complement**
1. Traverse list  
2. Flip each bit  
3. Store in new list  

### **2’s Complement**
1. Get 1’s complement  
2. Add 1 starting from tail  
3. Reverse final list  

### **Addition of Two Binary Numbers**
1. Start from tails of both lists  
2. Add bits and carry  
3. Store result bit  
4. Move to previous nodes  
5. Reverse result list  

---

## Code  
```cpp
// C++ program for binary operations using doubly linked list

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

```

---

## Sample Dry Run  
Input:  
```
First: 1010
Second: 0110
```

### 1’s Complement  
1010 → 0101  

### 2’s Complement  
0101 + 1 → 0110  

### Addition  
```
  1010
+ 0110
------
 10000
```

---

## Conclusion  
This program successfully demonstrates how binary numbers can be stored and processed using a doubly linked list. The operations such as 1’s complement, 2’s complement, and binary addition are efficiently performed using pointer-based traversal.
