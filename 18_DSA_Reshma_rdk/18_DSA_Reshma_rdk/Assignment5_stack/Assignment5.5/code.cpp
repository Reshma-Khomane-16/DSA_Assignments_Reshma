#include <iostream>
#include <cctype>
using namespace std;

// Node for stack
class Node {
public:
    int data_rdk;
    Node* next_rdk;

    Node(int val_rdk) {
        data_rdk = val_rdk;
        next_rdk = NULL;
    }
};

// Stack class
class Stack {
public:
    Node* top_rdk;

    Stack() {
        top_rdk = NULL;
    }

    void push_rdk(int val_rdk) {
        Node* newNode_rdk = new Node(val_rdk);
        newNode_rdk->next_rdk = top_rdk;
        top_rdk = newNode_rdk;
    }

    int pop_rdk() {
        if (top_rdk == NULL) return 0;
        Node* temp_rdk = top_rdk;
        int val_rdk = temp_rdk->data_rdk;
        top_rdk = top_rdk->next_rdk;
        delete temp_rdk;
        return val_rdk;
    }

    bool isEmpty_rdk() {
        return top_rdk == NULL;
    }
};

// Evaluate postfix expression
int evaluatePostfix_rdk(string expr_rdk) {
    Stack stack_rdk;

    for (int i_rdk = 0; i_rdk < expr_rdk.length(); i_rdk++) {
        char ch_rdk = expr_rdk[i_rdk];

        if (isdigit(ch_rdk)) {
            stack_rdk.push_rdk(ch_rdk - '0'); // Convert char to int
        } else {
            int val2_rdk = stack_rdk.pop_rdk();
            int val1_rdk = stack_rdk.pop_rdk();
            int result_rdk;

            switch (ch_rdk) {
                case '+': result_rdk = val1_rdk + val2_rdk; break;
                case '-': result_rdk = val1_rdk - val2_rdk; break;
                case '*': result_rdk = val1_rdk * val2_rdk; break;
                case '/': 
                    if(val2_rdk != 0)
                        result_rdk = val1_rdk / val2_rdk; 
                    else {
                        cout << "Error: Division by zero!\n";
                        return 0;
                    }
                    break;
                default:
                    cout << "Invalid operator: " << ch_rdk << endl;
                    return 0;
            }

            stack_rdk.push_rdk(result_rdk);
        }
    }

    return stack_rdk.pop_rdk();
}

int main() {
    string postfix_rdk;

    cout << "Enter postfix expression (single-digit operands, no spaces): ";
    cin >> postfix_rdk;

    int result_rdk = evaluatePostfix_rdk(postfix_rdk);
    cout << "Result of the postfix expression: " << result_rdk << endl;

    return 0;
}
