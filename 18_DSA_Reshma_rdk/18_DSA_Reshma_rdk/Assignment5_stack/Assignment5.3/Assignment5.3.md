# Multiple Stack Implementation Using Array

## Title
Multiple Stack Implementation Using Array

## Objective
To implement more than two stacks using a single array and perform push, pop, overflow, underflow, and display operations.

## Theory
A multiple stack structure divides a single array into fixed sections, each representing one independent stack. Each stack has its own top pointer. Overflow occurs when a stack exceeds its fixed section, and underflow occurs when attempting to pop from an empty stack.

## Algorithm
1. Initialize an array and divide it equally among all stacks.
2. Maintain a top index for each stack.
3. For push:
   - Check overflow.
   - Increment top and insert value.
4. For pop:
   - Check underflow.
   - Return and decrement top.
5. For display:
   - Print elements from the start of that stack's section up to top pointer.

## Code
```
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

```

## Output
Example operations:
Push 5 into Stack 1  
Push 10 into Stack 1  
Push 7 into Stack 2  
Display Stack 1 → 5 10  
Pop from Stack 2 → 7  

## Conclusion
Multiple stacks can be efficiently implemented using a single array by dividing the array equally. Each stack behaves independently with its own overflow and underflow conditions.
