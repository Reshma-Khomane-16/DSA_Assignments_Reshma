## Title
Polynomial Addition Using Singly Linked List

## Objective
To implement addition of two polynomials using singly linked lists in C++. Each term contains a coefficient and power, and the result must display a correctly simplified polynomial.

## Theory
A polynomial can be represented as a linked list where each node stores:
- `coeff` → coefficient  
- `pow` → power  
- `next` → pointer to next term  

Terms are stored in descending order of power.  
Polynomial addition works by comparing powers of the corresponding terms of two polynomials:
- If powers are equal → add coefficients  
- If one has a higher power → copy that term  
- Continue until both lists are traversed  

This approach avoids using arrays and dynamically handles polynomial sizes.

## Algorithm
1. Create a Node structure with coefficient, power, and next pointer.
2. Insert polynomial terms in sorted order (descending power).
3. To add two polynomials:
   - Compare powers of current terms.
   - If equal, add coefficients.
   - If not equal, append the term with the larger power.
4. Append remaining terms after one list finishes.
5. Display the resulting polynomial.

## Code
```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int coeff_rdk, pow_rdk;
    Node *next_rdk;

    Node(int c, int p) {
        coeff_rdk = c;
        pow_rdk = p;
        next_rdk = NULL;
    }
};

class Polynomial {
public:
    Node *head_rdk;

    Polynomial() {
        head_rdk = NULL;
    }

    // Insert term at end
    void insertTerm_rdk(int coeff_rdk, int pow_rdk) {
        Node *newNode_rdk = new Node(coeff_rdk, pow_rdk);
        if (head_rdk == NULL) {
            head_rdk = newNode_rdk;
            return;
        }
        Node *temp_rdk = head_rdk;
        while (temp_rdk->next_rdk != NULL)
            temp_rdk = temp_rdk->next_rdk;

        temp_rdk->next_rdk = newNode_rdk;
    }

    // Display polynomial
    void display_rdk() {
        if (head_rdk == NULL) {
            cout << "Polynomial is empty\n";
            return;
        }
        Node *temp_rdk = head_rdk;
        while (temp_rdk != NULL) {
            cout << temp_rdk->coeff_rdk << "x^" << temp_rdk->pow_rdk;
            if (temp_rdk->next_rdk != NULL)
                cout << " + ";
            temp_rdk = temp_rdk->next_rdk;
        }
        cout << endl;
    }

    // Add two polynomials
    static Polynomial add_rdk(Polynomial P1_rdk, Polynomial P2_rdk) {
        Polynomial result_rdk;
        Node *t1_rdk = P1_rdk.head_rdk;
        Node *t2_rdk = P2_rdk.head_rdk;

        while (t1_rdk != NULL && t2_rdk != NULL) {
            if (t1_rdk->pow_rdk == t2_rdk->pow_rdk) {
                result_rdk.insertTerm_rdk(t1_rdk->coeff_rdk + t2_rdk->coeff_rdk, t1_rdk->pow_rdk);
                t1_rdk = t1_rdk->next_rdk;
                t2_rdk = t2_rdk->next_rdk;
            } 
            else if (t1_rdk->pow_rdk > t2_rdk->pow_rdk) {
                result_rdk.insertTerm_rdk(t1_rdk->coeff_rdk, t1_rdk->pow_rdk);
                t1_rdk = t1_rdk->next_rdk;
            } 
            else {
                result_rdk.insertTerm_rdk(t2_rdk->coeff_rdk, t2_rdk->pow_rdk);
                t2_rdk = t2_rdk->next_rdk;
            }
        }

        // Remaining terms
        while (t1_rdk != NULL) {
            result_rdk.insertTerm_rdk(t1_rdk->coeff_rdk, t1_rdk->pow_rdk);
            t1_rdk = t1_rdk->next_rdk;
        }

        while (t2_rdk != NULL) {
            result_rdk.insertTerm_rdk(t2_rdk->coeff_rdk, t2_rdk->pow_rdk);
            t2_rdk = t2_rdk->next_rdk;
        }

        return result_rdk;
    }
};

int main() {
    Polynomial P1_rdk, P2_rdk, Result_rdk;
    int choice_rdk, coeff_rdk, pow_rdk;

    while (true) {
        cout << "\n===== POLYNOMIAL ADDITION MENU (Linked List) =====\n";
        cout << "1. Insert term in Polynomial 1\n";
        cout << "2. Insert term in Polynomial 2\n";
        cout << "3. Display Polynomial 1\n";
        cout << "4. Display Polynomial 2\n";
        cout << "5. Add Polynomials\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice_rdk;

        switch (choice_rdk) {
            case 1:
                cout << "Enter coefficient: ";
                cin >> coeff_rdk;
                cout << "Enter power: ";
                cin >> pow_rdk;
                P1_rdk.insertTerm_rdk(coeff_rdk, pow_rdk);
                break;

            case 2:
                cout << "Enter coefficient: ";
                cin >> coeff_rdk;
                cout << "Enter power: ";
                cin >> pow_rdk;
                P2_rdk.insertTerm_rdk(coeff_rdk, pow_rdk);
                break;

            case 3:
                cout << "Polynomial 1: ";
                P1_rdk.display_rdk();
                break;

            case 4:
                cout << "Polynomial 2: ";
                P2_rdk.display_rdk();
                break;

            case 5:
                cout << "Result (P1 + P2): ";
                Result_rdk = Polynomial::add_rdk(P1_rdk, P2_rdk);
                Result_rdk.display_rdk();
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}

```

## Sample Output
```
Enter number of terms in first polynomial: 3
Enter coefficient and power:
5 2
3 1
2 0

Enter number of terms in second polynomial: 3
Enter coefficient and power:
4 2
1 1
7 0

First Polynomial: 5x^2 + 3x^1 + 2x^0
Second Polynomial: 4x^2 + 1x^1 + 7x^0

Sum of Polynomials: 9x^2 + 4x^1 + 9x^0
```

## Dry Run
Let  
P1 = 5x² + 3x¹ + 2x⁰  
P2 = 4x² + 1x¹ + 7x⁰  

Step-by-step:
- Compare powers 2 & 2 → add → 9x²  
- Compare powers 1 & 1 → add → 4x¹  
- Compare powers 0 & 0 → add → 9x⁰  

Final result:
```
9x² + 4x¹ + 9x⁰
```

## Conclusion
Polynomial addition using singly linked lists is efficient and dynamically manages polynomial sizes.  
The implementation handles sorted insertion, matching powers, and produces a simplified result.

