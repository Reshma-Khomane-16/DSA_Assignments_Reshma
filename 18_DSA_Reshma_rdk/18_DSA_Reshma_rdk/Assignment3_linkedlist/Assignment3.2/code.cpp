/*The ticket reservation system for Galaxy Multiplex is to be implemented using a C++ program. 
The multiplex has 8 rows, with 8 seats in each row. A doubly circular linked list will be used 
to track the availability of seats in each row.Initially, assume that some seats are randomly booked. An array will store head pointers for each row’s linked list.The system should support the following operations:
a) Display the current list of available seats.
b) Book one or more seats as per customer request.
c) Cancel an existing booking when requested.*/	

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
