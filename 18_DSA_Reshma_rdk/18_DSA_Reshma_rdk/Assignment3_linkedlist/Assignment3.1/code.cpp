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
