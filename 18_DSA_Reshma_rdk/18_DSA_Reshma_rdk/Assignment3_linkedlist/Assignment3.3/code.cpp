/*Develop a C++ program to store and manage an appointment schedule for a single day. Appointments
 should be scheduled randomly using a linked list. The system must define the start time, end time,
 and specify the minimum and maximum duration allowed for each appointment slot.
The program should include the following operations:
a) Display the list of currently available time slots.
 b) Book a new appointment within the defined time limits.
 c) Cancel an existing appointment after validating its time, availability, and correctness.
 d) Sort the appointment list in order of appointment times.
 e) Sort the list based on appointment times using pointer manipulation (without swapping data
  values).*/
	

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
