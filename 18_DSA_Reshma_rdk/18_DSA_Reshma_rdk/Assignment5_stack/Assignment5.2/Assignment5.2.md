# Infix to Postfix Conversion Using Stack

## Title
Infix to Postfix Expression Conversion

## Objective
To convert a given infix expression into its postfix form using a stack and demonstrate the use of operator precedence.

## Theory
An infix expression places operators between operands, whereas postfix places operators after operands. Postfix expressions eliminate the need for parentheses and follow a specific evaluation order. A stack is used to hold operators and ensure they are output based on precedence.

## Algorithm
1. Initialize an empty stack for operators and an empty postfix string.
2. Scan each character of the infix expression.
3. If the scanned character is an operand, append it to postfix.
4. If it is an operator:
   - Pop operators from the stack with greater or equal precedence and append them to postfix.
   - Push the scanned operator onto the stack.
5. After scanning all characters, pop and append all remaining operators from the stack.
6. Output the postfix expression.

## Code
```
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

```

## Output
**Input:**  
a-b*c-d/e+f  

**Postfix Result:**  
abc*-de/-f+

## Dry Run
Expression: a-b*c-d/e+f

1. Read a → output: a  
2. Read - → push '-'  
3. Read b → output: ab  
4. Read * → higher precedence than '-' → push '*'  
5. Read c → output: abc  
6. Read - → pop '*' → output: abc*  
   pop '-' → output: abc*-  
   push '-'  
7. Read d → output: abc*-d  
8. Read / → higher precedence → push '/'  
9. Read e → output: abc*-de  
10. Read + → pop '/' → output: abc*-de/  
    pop '-' → output: abc*-de/-  
    push '+'  
11. Read f → output: abc*-de/-f  
12. End → pop '+' → final output: abc*-de/-f+

## Conclusion
The program successfully converts any valid infix expression to postfix using stack operations and operator precedence rules, ensuring correct evaluation order.
