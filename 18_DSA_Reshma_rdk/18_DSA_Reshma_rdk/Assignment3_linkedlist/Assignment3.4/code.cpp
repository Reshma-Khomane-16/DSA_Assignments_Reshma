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
