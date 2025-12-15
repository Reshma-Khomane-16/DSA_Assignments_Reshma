/*You are given a string containing only parentheses characters: '(', ')', '{', '}', '[', and ']'. Your task is to check whether the parentheses are balanced or not.
A string is considered balanced if:
1.	Every opening bracket has a corresponding closing bracket of the same type
2.	Brackets are closed in the correct order.*/	
#include <iostream>
using namespace std;

// Node for stack
class Node {
public:
    char data_rdk;
    Node* next_rdk;

    Node(char val_rdk) {
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

    void push_rdk(char val_rdk) {
        Node* newNode_rdk = new Node(val_rdk);
        newNode_rdk->next_rdk = top_rdk;
        top_rdk = newNode_rdk;
    }

    char pop_rdk() {
        if (top_rdk == NULL) return '\0';
        Node* temp_rdk = top_rdk;
        char val_rdk = temp_rdk->data_rdk;
        top_rdk = top_rdk->next_rdk;
        delete temp_rdk;
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

// Function to check matching brackets
bool isMatching_rdk(char open_rdk, char close_rdk) {
    return (open_rdk == '(' && close_rdk == ')') ||
           (open_rdk == '{' && close_rdk == '}') ||
           (open_rdk == '[' && close_rdk == ']');
}

// Function to check balanced parentheses
bool isBalanced_rdk(string expr_rdk) {
    Stack stack_rdk;

    for (int i_rdk = 0; i_rdk < expr_rdk.length(); i_rdk++) {
        char ch_rdk = expr_rdk[i_rdk];

        if (ch_rdk == '(' || ch_rdk == '{' || ch_rdk == '[') {
            stack_rdk.push_rdk(ch_rdk);
        } else if (ch_rdk == ')' || ch_rdk == '}' || ch_rdk == ']') {
            if (stack_rdk.isEmpty_rdk()) return false;
            if (!isMatching_rdk(stack_rdk.pop_rdk(), ch_rdk)) return false;
        }
    }

    return stack_rdk.isEmpty_rdk();
}

int main() {
    string expr_rdk;

    cout << "Enter expression with parentheses: ";
    cin >> expr_rdk;

    if (isBalanced_rdk(expr_rdk))
        cout << "The expression is balanced.\n";
    else
        cout << "The expression is NOT balanced.\n";

    return 0;
}
