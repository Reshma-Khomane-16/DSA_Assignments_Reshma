/*Write a program to keep track of patients as they checked into a medical clinic, assigning 
patients to doctors on a first-come, first-served basis.*/	
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
