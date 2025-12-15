## Titele
Patient Clinic Queue Management System

## Objective

To implement a queue-based system that keeps track of patients as they
check into a medical clinic and assigns them to doctors on a first-come,
first-served basis.

## Theory

A queue is a linear data structure that follows the First-In-First-Out
(FIFO) principle. The first element added to the queue is the first one
to be removed. This property makes queues suitable for scheduling and
managing waiting lines, such as patients in a clinic.

In this program: - Each patient is represented using a structure
containing name and age. - A queue is used to store patients in arrival
order. - Operations include check-in, calling the next patient, and
displaying the list of waiting patients.

## Algorithm

1.  Start the program.
2.  Initialize an empty queue to store patient details.
3.  Display menu options to the user.
4.  If the user selects:
    -   **Check-in patient:**
        -   Input name and age.
        -   Add patient to the queue.
    -   **Call next patient:**
        -   If queue is empty, display message.
        -   Otherwise, remove and display the first patient.
    -   **Display waiting patients:**
        -   If queue is empty, display message.
        -   Otherwise, traverse and display all patients in order.
    -   **Exit:** Terminate the program.
5.  Repeat menu until the user selects Exit.
6.  End the program.

## Code

``` cpp
#include <iostream>
using namespace std;

#define MAX_RDK 100  // Maximum number of patients

class ClinicQueue {
private:
    string patient_rdk[MAX_RDK];
    int front_rdk, rear_rdk;

public:
    ClinicQueue() {
        front_rdk = -1;
        rear_rdk = -1;
    }

    // Check if queue is empty
    bool isEmpty_rdk() {
        return front_rdk == -1;
    }

    // Check if queue is full
    bool isFull_rdk() {
        return rear_rdk == MAX_RDK - 1;
    }

    // Enqueue patient
    void addPatient_rdk(string name_rdk) {
        if (isFull_rdk()) {
            cout << "Clinic is full! Cannot add more patients.\n";
            return;
        }
        if (isEmpty_rdk()) front_rdk = 0;
        rear_rdk++;
        patient_rdk[rear_rdk] = name_rdk;
        cout << "Patient " << name_rdk << " added to the queue.\n";
    }

    // Dequeue patient (assign to doctor)
    void assignPatient_rdk() {
        if (isEmpty_rdk()) {
            cout << "No patients in the queue.\n";
            return;
        }
        cout << "Patient " << patient_rdk[front_rdk] << " assigned to doctor.\n";
        front_rdk++;
        if (front_rdk > rear_rdk) { // Queue becomes empty
            front_rdk = rear_rdk = -1;
        }
    }

    // Display queue
    void displayQueue_rdk() {
        if (isEmpty_rdk()) {
            cout << "No patients in the queue.\n";
            return;
        }
        cout << "Current Patients in Queue: ";
        for (int i_rdk = front_rdk; i_rdk <= rear_rdk; i_rdk++)
            cout << patient_rdk[i_rdk] << " ";
        cout << endl;
    }
};

int main() {
    ClinicQueue clinic_rdk;
    int choice_rdk;
    string name_rdk;

    do {
        cout << "\n=== MEDICAL CLINIC MENU ===\n";
        cout << "1. Add Patient\n2. Assign Patient to Doctor\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name_rdk;
                clinic_rdk.addPatient_rdk(name_rdk);
                break;
            case 2:
                clinic_rdk.assignPatient_rdk();
                break;
            case 3:
                clinic_rdk.displayQueue_rdk();
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

    Clinic Menu:
    1. Check-in a patient
    2. Call next patient
    3. Display waiting patients
    4. Exit
    Enter your choice: 1
    Enter patient's name: Rahul
    Enter patient's age: 30
    Patient Rahul checked in.

    Clinic Menu:
    Enter your choice: 1
    Enter patient's name: Sneha
    Enter patient's age: 25
    Patient Sneha checked in.

    Clinic Menu:
    Enter your choice: 3
    Waiting patients:
    - Rahul, Age: 30
    - Sneha, Age: 25

    Clinic Menu:
    Enter your choice: 2
    Calling patient: Rahul, Age: 30

    Clinic Menu:
    Enter your choice: 4
    Exiting system.

## Dry Run

### Input Sequence

1.  Check-in: Rahul, 30
2.  Check-in: Sneha, 25
3.  Display waiting patients
4.  Call next patient

### Execution

-   Queue after first check-in: \[Rahul\]
-   Queue after second check-in: \[Rahul, Sneha\]
-   Display shows both patients in order.
-   Call next removes Rahul; queue becomes: \[Sneha\]

## Conclusion

The program successfully simulates a clinic check-in system using a
queue. It effectively demonstrates queue operations such as insertion,
deletion, and traversal while applying the FIFO principle.
