## Assignment 3 - Appointment Scheduling System Report

## Title 
Appointment Scheduling System Report

## Objective
To develop a C++ program that manages a single-day appointment schedule using a linked list. The program generates random appointment slots within defined time limits and supports booking, cancellation, displaying available slots, and sorting appointments.

## Theory
A linked list is used to store appointment slots for the day. Each node represents an appointment with start time, end time, booking status, and a pointer to the next node. Random durations are assigned between the minimum and maximum duration limits until the end of the workday is reached. Operations include displaying slots, booking, canceling, and sorting using both data swapping and pointer manipulation.

## Algorithm
1. Initialize the schedule with a null head pointer.
2. Generate slots from start to end of the day using random durations.
3. Append each new appointment node to the linked list.
4. For displaying available slots, traverse the list and print unbooked nodes.
5. For booking, find the matching start time and mark the slot booked.
6. For cancellation, find the start time and reset the booking status.
7. For sorting with data swap, compare adjacent nodes and swap values.
8. For sorting using pointers, build a new sorted linked list by correct insertion.

## Code
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int start;
    int end;
    Node* next;

    Node(int s, int e) {
        start = s;
        end = e;
        next = NULL;
    }
};

class AppointmentList {
public:
    Node* head;

    AppointmentList() {
        head = NULL;
    }

    // Insert at correct position (sorted insertion)
    void insertSorted(int s, int e) {
        Node* newNode = new Node(s, e);

        if (!head || s < head->start) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->start < s)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Check overlapping
    bool isOverlapping(int s, int e) {
        Node* temp = head;

        while (temp) {
            if (!(e <= temp->start || s >= temp->end))
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display appointments
    void display() {
        if (!head) {
            cout << "No Appointments scheduled.\n";
            return;
        }

        Node* temp = head;
        cout << "\nScheduled Appointments:\n";
        while (temp) {
            cout << temp->start << " - " << temp->end << endl;
            temp = temp->next;
        }
    }

    // Display available slots
    void displayAvailable(int dayStart, int dayEnd) {
        cout << "\nAvailable Time Slots:\n";

        Node* temp = head;
        int curr = dayStart;

        while (temp) {
            if (curr < temp->start)
                cout << curr << " - " << temp->start << endl;
            curr = temp->end;
            temp = temp->next;
        }

        if (curr < dayEnd)
            cout << curr << " - " << dayEnd << endl;
    }

    // Book appointment
    void book(int s, int e, int minDur, int maxDur) {
        if (e - s < minDur || e - s > maxDur) {
            cout << "Invalid duration!\n";
            return;
        }

        if (isOverlapping(s, e)) {
            cout << "Slot overlaps with existing appointment!\n";
            return;
        }

        insertSorted(s, e);
        cout << "Appointment booked successfully!\n";
    }

    // Cancel
    void cancel(int s) {
        if (!head) {
            cout << "No appointments to cancel.\n";
            return;
        }

        if (head->start == s) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Appointment cancelled.\n";
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->start != s)
            temp = temp->next;

        if (!temp->next) {
            cout << "Appointment not found.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;
        cout << "Appointment cancelled.\n";
    }

    // Sort by data swapping
    void sortData() {
        if (!head) return;

        Node* i = head;
        while (i) {
            Node* j = i->next;
            while (j) {
                if (i->start > j->start) {
                    swap(i->start, j->start);
                    swap(i->end, j->end);
                }
                j = j->next;
            }
            i = i->next;
        }
        cout << "List sorted by swapping data.\n";
    }

    // Sort using pointer manipulation only
    void sortPointer() {
        Node* sorted = NULL;

        while (head) {
            Node* temp = head;
            head = head->next;

            if (!sorted || temp->start < sorted->start) {
                temp->next = sorted;
                sorted = temp;
            } else {
                Node* curr = sorted;
                while (curr->next && curr->next->start < temp->start)
                    curr = curr->next;
                temp->next = curr->next;
                curr->next = temp;
            }
        }
        head = sorted;

        cout << "List sorted by pointer manipulation.\n";
    }
};

int main() {
    AppointmentList list;

    int choice_rdk;
    int dayStart_rdk = 9, dayEnd_rdk = 17;     // Working hours: 9 AM - 5 PM
    int minDur_rdk = 1, maxDur_rdk = 3;        // Duration limits
    int s_rdk, e_rdk;

    do {
        cout << "\n====== APPOINTMENT SCHEDULER ======\n";
        cout << "1. Display Scheduled Appointments\n";
        cout << "2. Display Available Time Slots\n";
        cout << "3. Book Appointment\n";
        cout << "4. Cancel Appointment\n";
        cout << "5. Sort by Data Swapping\n";
        cout << "6. Sort by Pointer Manipulation\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
        case 1:
            list.display();
            break;

        case 2:
            list.displayAvailable(dayStart_rdk, dayEnd_rdk);
            break;

        case 3:
            cout << "Enter start time: ";
            cin >> s_rdk;
            cout << "Enter end time: ";
            cin >> e_rdk;
            list.book(s_rdk, e_rdk, minDur_rdk, maxDur_rdk);
            break;

        case 4:
            cout << "Enter start time of appointment to cancel: ";
            cin >> s_rdk;
            list.cancel(s_rdk);
            break;

        case 5:
            list.sortData();
            break;

        case 6:
            list.sortPointer();
            break;

        case 7:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice_rdk != 7);

    return 0;
}

```
## output

C:\Users\Pioneer\Desktop\DSA_CPP>13Appointm
ent.exe

====== APPOINTMENT SCHEDULER ======        
1. Display Scheduled Appointments
2. Display Available Time Slots
3. Book Appointment
4. Cancel Appointment
5. Sort by Data Swapping
6. Sort by Pointer Manipulation
7. Exit
Enter choice: 3
Enter start time: 12
Enter end time: 3
Invalid duration!

====== APPOINTMENT SCHEDULER ======        
1. Display Scheduled Appointments
2. Display Available Time Slots
3. Book Appointment
4. Cancel Appointment
5. Sort by Data Swapping
6. Sort by Pointer Manipulation
7. Exit
Enter choice: 3
Enter start time: 6
Enter end time: 7
Appointment booked successfully!

====== APPOINTMENT SCHEDULER ======        
1. Display Scheduled Appointments
2. Display Available Time Slots
3. Book Appointment
4. Cancel Appointment
5. Sort by Data Swapping
6. Sort by Pointer Manipulation
7. Exit
Enter choice: 2

Available Time Slots:
7 - 17

====== APPOINTMENT SCHEDULER ======        
1. Display Scheduled Appointments
2. Display Available Time Slots
3. Book Appointment
4. Cancel Appointment
5. Sort by Data Swapping
6. Sort by Pointer Manipulation
7. Exit
Enter choice: 1

Scheduled Appointments:
6 - 7

====== APPOINTMENT SCHEDULER ======        
1. Display Scheduled Appointments
2. Display Available Time Slots
3. Book Appointment
4. Cancel Appointment
5. Sort by Data Swapping
6. Sort by Pointer Manipulation
7. Exit
Enter choice: 5
List sorted by swapping data.

====== APPOINTMENT SCHEDULER ======        
1. Display Scheduled Appointments
2. Display Available Time Slots
3. Book Appointment
4. Cancel Appointment
5. Sort by Data Swapping
6. Sort by Pointer Manipulation
7. Exit
Enter choice: 2

Available Time Slots:
7 - 17

## Dry Run
If the generated slots are:
- 9 to 10 Available
- 10 to 12 Booked
- 12 to 13 Available

Booking at 9 sets the 9–10 slot to booked. Cancelling at 10 resets the 10–12 slot to available. Sorting rearranges nodes in increasing start time order.

## Conclusion
The linked list based appointment scheduling system successfully manages random daily appointment slots, supports booking, cancellation, and provides two sorting methods. The program demonstrates efficient use of dynamic data structures for time-based scheduling tasks.
