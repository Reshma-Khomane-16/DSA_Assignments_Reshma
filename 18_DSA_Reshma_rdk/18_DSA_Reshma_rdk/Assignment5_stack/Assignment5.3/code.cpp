/*Write a program to implement multiple stack i.e more than two stack using array and perform 
following operations on it. A. Push B. Pop C. Stack Overflow D. Stack Underflow E. Display*/
#include <iostream>
using namespace std;

#define MAX_RDK 100   // Maximum size of array

class MultiStack {
private:
    int arr_rdk[MAX_RDK];
    int top_rdk[3]; // Assuming 3 stacks
    int n_rdk = MAX_RDK / 3; // Each stack gets equal partition

public:
    MultiStack() {
        for (int i_rdk = 0; i_rdk < 3; i_rdk++)
            top_rdk[i_rdk] = -1;  // Initialize tops
    }

    // Push element into stack_num (1,2,3)
    void push_rdk(int stack_num_rdk, int val_rdk) {
        if (stack_num_rdk < 1 || stack_num_rdk > 3) {
            cout << "Invalid stack number!\n";
            return;
        }

        int index_rdk = top_rdk[stack_num_rdk - 1] + 1;

        if (index_rdk >= n_rdk) {
            cout << "Stack Overflow in stack " << stack_num_rdk << "!\n";
            return;
        }

        top_rdk[stack_num_rdk - 1]++;
        arr_rdk[(stack_num_rdk - 1) * n_rdk + top_rdk[stack_num_rdk - 1]] = val_rdk;
        cout << "Pushed " << val_rdk << " into stack " << stack_num_rdk << endl;
    }

    // Pop element from stack_num
    void pop_rdk(int stack_num_rdk) {
        if (stack_num_rdk < 1 || stack_num_rdk > 3) {
            cout << "Invalid stack number!\n";
            return;
        }

        if (top_rdk[stack_num_rdk - 1] == -1) {
            cout << "Stack Underflow in stack " << stack_num_rdk << "!\n";
            return;
        }

        int val_rdk = arr_rdk[(stack_num_rdk - 1) * n_rdk + top_rdk[stack_num_rdk - 1]];
        top_rdk[stack_num_rdk - 1]--;
        cout << "Popped " << val_rdk << " from stack " << stack_num_rdk << endl;
    }

    // Display stack elements
    void display_rdk(int stack_num_rdk) {
        if (stack_num_rdk < 1 || stack_num_rdk > 3) {
            cout << "Invalid stack number!\n";
            return;
        }

        if (top_rdk[stack_num_rdk - 1] == -1) {
            cout << "Stack " << stack_num_rdk << " is empty!\n";
            return;
        }

        cout << "Stack " << stack_num_rdk << ": ";
        for (int i_rdk = 0; i_rdk <= top_rdk[stack_num_rdk - 1]; i_rdk++)
            cout << arr_rdk[(stack_num_rdk - 1) * n_rdk + i_rdk] << " ";
        cout << endl;
    }
};

int main() {
    MultiStack stack_rdk;
    int choice_rdk, stack_num_rdk, val_rdk;

    do {
        cout << "\n=== MULTIPLE STACK MENU ===\n";
        cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter stack number (1-3): ";
                cin >> stack_num_rdk;
                cout << "Enter value to push: ";
                cin >> val_rdk;
                stack_rdk.push_rdk(stack_num_rdk, val_rdk);
                break;

            case 2:
                cout << "Enter stack number (1-3): ";
                cin >> stack_num_rdk;
                stack_rdk.pop_rdk(stack_num_rdk);
                break;

            case 3:
                cout << "Enter stack number (1-3): ";
                cin >> stack_num_rdk;
                stack_rdk.display_rdk(stack_num_rdk);
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
