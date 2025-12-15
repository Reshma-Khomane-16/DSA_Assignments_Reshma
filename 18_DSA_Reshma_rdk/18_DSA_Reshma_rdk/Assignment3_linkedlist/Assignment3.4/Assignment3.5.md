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
    int prn;
    Node* next;

    Node(int p) {
        prn = p;
        next = NULL;
    }
};

class SetList {
public:
    Node* head;

    SetList() {
        head = NULL;
    }

    void insert(int p) {
        Node* newNode = new Node(p);
        newNode->next = head;
        head = newNode;
    }

    bool search(int p) {
        Node* temp = head;
        while (temp) {
            if (temp->prn == p) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        if (!head) {
            cout << "{ }";
            return;
        }
        Node* temp = head;
        cout << "{ ";
        while (temp) {
            cout << temp->prn << " ";
            temp = temp->next;
        }
        cout << "}";
    }
};

SetList intersection(SetList &A, SetList &B) {
    SetList result;
    Node* temp = A.head;

    while (temp) {
        if (B.search(temp->prn))
            result.insert(temp->prn);
        temp = temp->next;
    }
    return result;
}

SetList symmetricDifference(SetList &A, SetList &B) {
    SetList result;
    Node* temp = A.head;

    while (temp) {
        if (!B.search(temp->prn))
            result.insert(temp->prn);
        temp = temp->next;
    }

    temp = B.head;
    while (temp) {
        if (!A.search(temp->prn))
            result.insert(temp->prn);
        temp = temp->next;
    }

    return result;
}

int countNeither(SetList &All, SetList &A, SetList &B) {
    int count = 0;
    Node* temp = All.head;

    while (temp) {
        if (!A.search(temp->prn) && !B.search(temp->prn))
            count++;
        temp = temp->next;
    }
    return count;
}

int main() 
{
    SetList A, B, All;  // Cricket, Football, All students

    int choice_rdk, prn_rdk;

    do {
        cout << "\n===== SET OPERATIONS MENU =====\n";
        cout << "1. Add student to Cricket (Set A)\n";
        cout << "2. Add student to Football (Set B)\n";
        cout << "3. Add student to All Students List\n";
        cout << "4. Show both Cricket & Football (A ∩ B)\n";
        cout << "5. Show either Cricket or Football but not both (A ⊕ B)\n";
        cout << "6. Count students liking neither Cricket nor Football\n";
        cout << "7. Display Set A\n";
        cout << "8. Display Set B\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            cout << "Enter PRN to insert in Cricket: ";
            cin >> prn_rdk;
            A.insert(prn_rdk);
            break;

        case 2:
            cout << "Enter PRN to insert in Football: ";
            cin >> prn_rdk;
            B.insert(prn_rdk);
            break;

        case 3:
            cout << "Enter PRN to add to all students list: ";
            cin >> prn_rdk;
            All.insert(prn_rdk);
            break;

        case 4: {
            cout << "Students who like BOTH Cricket and Football:\n";
            SetList inter = intersection(A, B);
            inter.display();
            cout << endl;
            break;
        }

        case 5: {
            cout << "Students who like EITHER Cricket or Football but NOT both:\n";
            SetList sym = symmetricDifference(A, B);
            sym.display();
            cout << endl;
            break;
        }

        case 6: {
            int count_rdk = countNeither(All, A, B);
            cout << "Students liking NEITHER Cricket nor Football: " << count_rdk << endl;
            break;
        }

        case 7:
            cout << "Set A (Cricket lovers): ";
            A.display();
            cout << endl;
            break;

        case 8:
            cout << "Set B (Football lovers): ";
            B.display();
            cout << endl;
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice_rdk != 9);

    return 0;
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
