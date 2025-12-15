## Assignment 2- Galaxy Multiplex Ticket Reservation System

## Title

Implementation of Ticket Reservation System using Doubly Circular Linked
List

## Objective

To develop a C++ program for Galaxy Multiplex that maintains seat
availability using doubly circular linked lists. The system should allow
seat display, booking, and cancellation across 8 rows with 8 seats each.

## Theory

A doubly circular linked list is used to represent each row of the
multiplex.\
Each row contains 8 seats arranged in a circular structure where: -
Every seat has a **next** and **previous** pointer. - The last seat
points back to the first, forming a continuous loop.

Seat status: - 0 → Available\
- 1 → Booked

An array of 8 Row objects is used to maintain 8 rows of the multiplex.

Operations supported: 1. Display availability of all seats. 2. Book one
or more seats. 3. Cancel existing bookings.

## Algorithm

### Create Row

1.  For each of the 8 seats:
    -   Create seat node.
    -   Link each seat in both forward and backward directions.
    -   Last seat connects back to the head.

### Display Row

1.  Start from head.
2.  Traverse until head is reached again.
3.  Print A(seat_no) for available and B(seat_no) for booked.

### Book Seat

1.  Traverse seats until seat number matches.
2.  If already booked, print message.
3.  Otherwise, mark seat as booked.

### Cancel Seat

1.  Traverse seats until seat number matches.
2.  If not booked, print message.
3.  Otherwise, mark seat as available.

### Display All Rows

1.  Repeat displayRow() for all 8 rows.

## Code

``` cpp
#include <iostream>
#include <cstdlib>
using namespace std;

// Node for each seat
class Seat {
public:
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;

    Seat(int n) {
        seatNo = n;
        booked = false;
        next = prev = NULL;
    }
};

// Class for each row (Doubly Circular Linked List)
class Row {
public:
    Seat* head;

    Row() { head = NULL; }

    // Create row of 8 seats
    void createRow() {
        for (int i = 1; i <= 8; i++) {
            Seat* newSeat = new Seat(i);
            if (head == NULL) {
                head = newSeat;
                head->next = head;
                head->prev = head;
            } else {
                Seat* last = head->prev;
                last->next = newSeat;
                newSeat->prev = last;
                newSeat->next = head;
                head->prev = newSeat;
            }
        }
    }

    // Display all seats with availability
    void displayRow() {
        Seat* temp = head;
        cout << "Seats: ";
        do {
            if (temp->booked)
                cout << "[X] ";
            else
                cout << "[" << temp->seatNo << "] ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Book a specific seat
    bool bookSeat(int n) {
        Seat* temp = head;
        do {
            if (temp->seatNo == n) {
                if (temp->booked == false) {
                    temp->booked = true;
                    return true;
                } else
                    return false;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    // Cancel a specific seat
    bool cancelSeat(int n) {
        Seat* temp = head;
        do {
            if (temp->seatNo == n) {
                if (temp->booked == true) {
                    temp->booked = false;
                    return true;
                } else
                    return false;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }
};

int main() {
    Row multiplex_rdk[8];   // Array for 8 rows
    int choice_rdk, row_rdk, seat_rdk, n_rdk;

    // Create all rows
    for (int i = 0; i < 8; i++)
        multiplex_rdk[i].createRow();

    // Randomly book some seats initially
    for (int i = 0; i < 8; i++) {
        int randomSeats = rand() % 4; // book 0–3 seats randomly
        for (int j = 0; j < randomSeats; j++) {
            int s = (rand() % 8) + 1;
            multiplex_rdk[i].bookSeat(s);
        }
    }

    do {
        cout << "\n===== GALAXY MULTIPLEX TICKET SYSTEM =====\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seat(s)\n";
        cout << "3. Cancel Booking\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            for (int i = 0; i < 8; i++) {
                cout << "Row " << (i + 1) << ": ";
                multiplex_rdk[i].displayRow();
            }
            break;

        case 2:
            cout << "Enter Row (1–8): ";
            cin >> row_rdk;
            cout << "How many seats to book? ";
            cin >> n_rdk;

            for (int i = 0; i < n_rdk; i++) {
                cout << "Enter Seat No (1–8): ";
                cin >> seat_rdk;
                if (multiplex_rdk[row_rdk - 1].bookSeat(seat_rdk))
                    cout << "Seat booked successfully!\n";
                else
                    cout << "Seat already booked or invalid.\n";
            }
            break;

        case 3:
            cout << "Enter Row (1–8): ";
            cin >> row_rdk;
            cout << "Enter Seat No (1–8): ";
            cin >> seat_rdk;

            if (multiplex_rdk[row_rdk - 1].cancelSeat(seat_rdk))
                cout << "Booking cancelled successfully!\n";
            else
                cout << "Seat not booked or invalid.\n";
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

    C:\Users\Pioneer\Desktop\DSA_CPP>12Assign_ticket.exe 

===== GALAXY MULTIPLEX TICKET SYSTEM ===== 
1. Display Available Seats
2. Book Seat(s)
3. Cancel Booking
4. Exit
Enter choice: 2
Enter Row (1–8): 6
How many seats to book? 2
Enter Seat No (1–8): 4 5
Seat booked successfully!
Enter Seat No (1–8): Seat booked successfully!

===== GALAXY MULTIPLEX TICKET SYSTEM ===== 
1. Display Available Seats
2. Book Seat(s)
3. Cancel Booking
4. Exit
Enter choice: 1
Row 1: Seats: [1] [2] [3] [X] [5] [6] [7] [8]
Row 2: Seats: [1] [X] [3] [4] [X] [6] [7] [8]
Row 3: Seats: [1] [2] [3] [4] [5] [6] [7] [8]
Row 4: Seats: [1] [2] [X] [4] [5] [6] [X] [8]
Row 5: Seats: [1] [2] [3] [4] [5] [6] [7] [8]
Row 6: Seats: [1] [X] [3] [X] [X] [6] [7] [8]
Row 7: Seats: [1] [2] [3] [X] [5] [6] [7] [8]
Row 8: Seats: [1] [2] [3] [X] [5] [6] [7] [8]

===== GALAXY MULTIPLEX TICKET SYSTEM ===== 