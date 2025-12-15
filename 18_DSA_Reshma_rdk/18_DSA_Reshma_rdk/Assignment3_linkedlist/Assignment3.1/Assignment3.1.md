## Assignment 1-  Vertex Club Membership Management using Singly Linked List

## Title

Implementation of Singly Linked List to Manage Vertex Club Membership
Records

## Objective

To implement a C++ program that maintains the membership details of the
Vertex Club using a singly linked list. The program should support
adding and deleting members, displaying and counting members,
concatenating two lists, searching, sorting, and reversing the list.

## Theory

A singly linked list is a linear data structure where each node contains
data and a pointer to the next node. It allows efficient insertion and
deletion operations.

For the Vertex Club: - The first node is the President. - The last node
is the Secretary. - All other nodes are general members.

The program performs operations such as insertion, deletion, searching,
sorting, reversing, and concatenation.

## Algorithm

### Add President

1.  Create a new node.
2.  Set newNode-\>next to head.
3.  Update head to newNode.

### Add Secretary

1.  Create a new node.
2.  Traverse the list to the last node.
3.  Link lastNode-\>next to newNode.

### Add Member

1.  Traverse to the second last node.
2.  Insert new node before the Secretary.

### Delete Member

1.  If PRN matches head, delete President.
2.  Otherwise search through list.
3.  Adjust pointers and delete the node.

### Reverse List

1.  Use three pointers: prev, current, next.
2.  Reverse links iteratively.
3.  Update head.

### Search by PRN

1.  Traverse through each node.
2.  If PRN matches, print details.
3.  Else print not found.

### Sort by PRN

1.  Use bubble sort by swapping PRN and name values.

### Concatenate Lists

1.  Traverse to end of first list.
2.  Link last node to head of second list.

## Code

#include <iostream>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

Node* createNode(int prn, string name)
 {
    Node* temp = new Node;
    temp->prn = prn;
    temp->name = name;
    temp->next = NULL;
    return temp;
}

void insertPresident(Node*& head, int prn, string name) 
{
    Node* temp = createNode(prn, name);
    temp->next = head;
    head = temp;
}

void insertSecretary(Node*& head, int prn, string name)
 {
    Node* temp = createNode(prn, name);

    if (head == NULL) {
        head = temp;
        return;
    }
    Node* t = head;
    while (t->next != NULL)
        t = t->next;

    t->next = temp;
}

void deletePresident(Node*& head)
 {
    if (head == NULL) return;

    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteSecretary(Node*& head)
 {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* t = head;
    while (t->next->next != NULL)
        t = t->next;

    delete t->next;
    t->next = NULL;
}

void displayList(Node* head)
 {
    cout << "\nPRN\tName\n";
    Node* t = head;
    while (t != NULL) {
        cout << t->prn << "\t" << t->name << endl;
        t = t->next;
    }
}
int countMembers(Node* head) 
{
    int count = 0;
    Node* t = head;
    while (t != NULL) {
        count++;
        t = t->next;
    }
    return count;
}

Node* searchByPRN(Node* head, int prn) 
{
    Node* t = head;
    while (t != NULL) {
        if (t->prn == prn)
            return t;
        t = t->next;
    }
    return NULL;
}

Node* reverseList(Node* head) 
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void sortByPRN(Node*& head) 
{
    if (head == NULL) return;

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = head; j->next != NULL; j = j->next) {
            if (j->prn > j->next->prn)
             {
                swap(j->prn, j->next->prn);
                swap(j->name, j->next->name);
            }
        }
    }
}

Node* concatenate(Node* head1, Node* head2) 
{
    if (head1 == NULL) return head2;
    Node* t = head1;

    while (t->next != NULL)
        t = t->next;

    t->next = head2;
    return head1;
}
int main() 
{
    Node* listA_rdk = NULL;
    Node* listB_rdk = NULL;

    int choice_rdk, prn_rdk;
    string name_rdk;

    do {
        cout << "\n===== VERTEX CLUB MENU =====\n";
        cout << "1. Add President\n";
        cout << "2. Add Secretary\n";
        cout << "3. Delete President\n";
        cout << "4. Delete Secretary\n";
        cout << "5. Display Members\n";
        cout << "6. Count Members\n";
        cout << "7. Search by PRN\n";
        cout << "8. Reverse List\n";
        cout << "9. Sort by PRN\n";
        cout << "10. Concatenate Another List\n";
        cout << "11. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            cout << "Enter PRN & Name: ";
            cin >> prn_rdk >> name_rdk;
            insertPresident(listA_rdk, prn_rdk, name_rdk);
            break;

        case 2:
            cout << "Enter PRN & Name: ";
            cin >> prn_rdk >> name_rdk;
            insertSecretary(listA_rdk, prn_rdk, name_rdk);
            break;

        case 3:
            deletePresident(listA_rdk);
            break;

        case 4:
            deleteSecretary(listA_rdk);
            break;

        case 5:
            displayList(listA_rdk);
            break;

        case 6:
            cout << "Total Members = " << countMembers(listA_rdk) << endl;
            break;

        case 7:
            cout << "Enter PRN to search: ";
            cin >> prn_rdk;
            if (searchByPRN(listA_rdk, prn_rdk))
                cout << "Member Found!\n";
            else
                cout << "Member Not Found!\n";
            break;

        case 8:
            listA_rdk = reverseList(listA_rdk);
            cout << "List Reversed.\n";
            break;

        case 9:
            sortByPRN(listA_rdk);
            cout << "List Sorted.\n";
            break;

        case 10:
            cout << "Enter elements for second list (enter 0 to stop):\n";
            while (true) 
            {
                cout << "Enter PRN: ";
                cin >> prn_rdk;
                if (prn_rdk == 0) break;
                cout << "Enter Name: ";
                cin >> name_rdk;
                insertSecretary(listB_rdk, prn_rdk, name_rdk);
            }
            listA_rdk = concatenate(listA_rdk, listB_rdk);
            cout << "Lists Concatenated.\n";
            break;

        case 11:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while (choice_rdk != 11);

    return 0;
}



## Sample Output

    ====== Vertex Club Menu ======
   C:\Users\Pioneer\Desktop\DSA_CPP>11Assign_s
ll.exe

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 1
Enter PRN & Name: 18
Reshma

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 2
Enter PRN & Name: 20
Prachi

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 5

PRN     Name
18      Reshma
20      Prachi

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 6
Total Members = 2

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 7
Enter PRN to search: 20
Member Found!

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 8
List Reversed.

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 5

PRN     Name
20      Prachi
18      Reshma

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 9
List Sorted.

===== VERTEX CLUB MENU =====
1. Add President
2. Add Secretary
3. Delete President
4. Delete Secretary
5. Display Members
6. Count Members
7. Search by PRN
8. Reverse List
9. Sort by PRN
10. Concatenate Another List
11. Exit
Enter choice: 5

PRN     Name
18      Reshma
20      Prachi

## Dry Run Example

### Input Operations

-   Add President: (10, A)
-   Add Member: (20, B)
-   Add Secretary: (30, C)

### Step-by-step List Construction

After adding President:

    [A] → NULL

After adding Member:

    [A] → [B] → NULL

After adding Secretary:

    [A] → [B] → [C] → NULL

After reverse:

    [C] → [B] → [A] → NULL
