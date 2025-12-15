/*Convert given infix expression Eg. a-b*c-d/e+f into postfix form using stack and show the 
operations step by step.*/
#include <iostream>
#include <cctype> // For isalpha
using namespace std;

// Node class for stack
class Node {
public:
    char data_rdk;
    Node* next_rdk;

    Node(char val_rdk) {
        data_rdk = val_rdk;
        next_rdk = NULL;
    }
};

// Stack class using linked list
class Stack {
public:
    Node* top_rdk;

    Stack() {
        top_rdk = NULL;
    }

    void push_rdk(char val_rdk) {
        Node* newNode_rdk = new Node(val_rdk);
        newNode_rdk->next_rdk = top_rdk;
        top_rdk = newNode_rdk;
        cout << "Push '" << val_rdk << "' to stack\n";
    }

    char pop_rdk() {
        if (top_rdk == NULL) {
            return '\0';
        }
        Node* temp_rdk = top_rdk;
        char val_rdk = temp_rdk->data_rdk;
        top_rdk = top_rdk->next_rdk;
        delete temp_rdk;
        cout << "Pop '" << val_rdk << "' from stack\n";
        return val_rdk;
    }

    char peek_rdk() {
        if (top_rdk == NULL) return '\0';
        return top_rdk->data_rdk;
    }

    bool isEmpty_rdk() {
        return top_rdk == NULL;
    }
};

// Function to get precedence
int precedence_rdk(char op_rdk) {
    if (op_rdk == '+' || op_rdk == '-') return 1;
    if (op_rdk == '*' || op_rdk == '/') return 2;
    return 0;
}

// Convert infix to postfix
void infixToPostfix_rdk(string infix_rdk) {
    Stack stack_rdk;
    string postfix_rdk = "";

    cout << "Converting Infix: " << infix_rdk << " to Postfix\n";

    for (int i_rdk = 0; i_rdk < infix_rdk.length(); i_rdk++) {
        char ch_rdk = infix_rdk[i_rdk];

        if (isalpha(ch_rdk)) {
            postfix_rdk += ch_rdk;
            cout << "Add operand '" << ch_rdk << "' to postfix: " << postfix_rdk << endl;
        } else { // Operator
            while (!stack_rdk.isEmpty_rdk() && precedence_rdk(stack_rdk.peek_rdk()) >= precedence_rdk(ch_rdk)) {
                postfix_rdk += stack_rdk.pop_rdk();
                cout << "Postfix so far: " << postfix_rdk << endl;
            }
            stack_rdk.push_rdk(ch_rdk);
        }
    }

    // Pop remaining operators
    while (!stack_rdk.isEmpty_rdk()) {
        postfix_rdk += stack_rdk.pop_rdk();
        cout << "Postfix so far: " << postfix_rdk << endl;
    }

    cout << "Final Postfix Expression: " << postfix_rdk << endl;
}

int main() {
    string infix_rdk;

    cout << "Enter infix expression (e.g., a-b*c-d/e+f): ";
    cin >> infix_rdk;

    infixToPostfix_rdk(infix_rdk);

    return 0;
}
