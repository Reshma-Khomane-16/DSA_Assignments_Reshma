# Evaluation of Postfix Expression Using Stack

## Title
Evaluation of Postfix Expression Using Stack

## Objective
To evaluate a postfix (Reverse Polish Notation) expression containing single‑digit operands and binary operators using a stack.

## Theory
A postfix expression is evaluated from left to right.  
- When an operand is encountered, push it onto the stack.  
- When an operator is encountered, pop the top two values, apply the operator, and push the result back.  
- The final value left in the stack is the evaluated result.

## Algorithm
1. Initialize an empty stack.
2. Read the postfix expression from left to right.
3. If the character is an operand, push it onto the stack.
4. If it is an operator:
   - Pop the top two operands.
   - Apply the operator.
   - Push the result back.
5. After processing the expression, the top of the stack is the final result.

## Code
```cpp
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

```

## Dry Run  
### Example Input  
```
53+2*
```

| Step | Read | Action | Stack |
|------|------|---------|--------|
| 1 | 5 | Operand → Push | 5 |
| 2 | 3 | Operand → Push | 5, 3 |
| 3 | + | Pop 3 & 5 → 5+3=8 → Push | 8 |
| 4 | 2 | Operand → Push | 8, 2 |
| 5 | * | Pop 2 & 8 → 8×2=16 → Push | 16 |

Final Result → **16**

## Output
Example execution:

```
Enter postfix expression: 53+2*
Result: 16
```

## Conclusion
Postfix expressions can be efficiently evaluated using stacks due to their operator-before-operand structure, eliminating the need for parentheses and precedence rules.
