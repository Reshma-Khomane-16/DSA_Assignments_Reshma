## Balanced Parentheses Checker

## Title

Balanced Parentheses Using Stack

## Objective

To check whether a given string of brackets is balanced using stack
operations.

## Theory

A string containing brackets is considered balanced if every opening
bracket has a corresponding closing bracket of the same type and the
brackets close in the correct order. A stack is used to store opening
brackets and match them with closing ones.

## Algorithm

1.  Initialize an empty stack.
2.  Traverse each character of the string.
3.  If an opening bracket is found, push it onto the stack.
4.  If a closing bracket is found:
    -   If the stack is empty, return Not Balanced.
    -   Pop the top element and check if it matches the type.
5.  After traversal, if the stack is empty, the string is Balanced;
    otherwise Not Balanced.

## Code

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

```

## Output

    Menu:
    1. Check Balanced Parentheses
    2. Exit
    Enter your choice: 1
    Enter parentheses string: {[()]}
    Balanced

## Dry Run

Expression: `{[()]}`

  Character   Stack   Action
  ----------- ------- -------------------
  {           {       Push
  \[          {\[     Push
  (           {\[ (   Push
  )           {\[     Pop ( matched )
  \]          {       Pop \[ matched \]
  }           empty   Pop { matched }

Stack empty → Balanced

## Conclusion

The stack-based approach efficiently checks balanced parentheses by
ensuring correct order and matching of bracket types.
