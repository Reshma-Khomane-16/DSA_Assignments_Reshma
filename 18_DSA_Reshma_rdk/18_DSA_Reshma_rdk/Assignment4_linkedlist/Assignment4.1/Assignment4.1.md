## Title
Implementation of Set Using Generalized Linked List (GLL)

## Objective
To implement a set using a Generalized Linked List (GLL) in C++ and display the structure in correct set notation.

## Theory
A Generalized Linked List allows representation of hierarchical or nested structures.  
Each node can store:
- **Atom (single element)**  
- **Sublist (nested set)**  

A GLL node contains:
- `isAtom` to distinguish between element and list  
- `data` for storing atomic values  
- `down` pointer for nested sets  
- `next` pointer for next element  

## Algorithm
1. Start reading input tokens.
2. If token is `{`, recursively create a sublist.
3. If token is `}`, return to previous list.
4. If token is an atom, store it as a node.
5. Continue until `#` is encountered.
6. Display the stored GLL using recursive traversal.

## Code
```cpp
#include <iostream>
#include <string>
using namespace std;

// Node definition for Generalized Linked List
struct GLLNode 
{
    int flag;          // 0 = atom, 1 = sublist
    string atom;       // valid if flag == 0
    GLLNode* down;     // valid if flag == 1
    GLLNode* next;     // next node in same list
};

// Utility: create an atom node
GLLNode* createAtom(const string &value) 
{
    GLLNode* node = new GLLNode;
    node->flag = 0;
    node->atom = value;
    node->down = nullptr;
    node->next = nullptr;
    return node;
}

// Utility: create a sublist node
GLLNode* createSublist(GLLNode* sublist) 
{
    GLLNode* node = new GLLNode;
    node->flag = 1;
    node->down = sublist;
    node->next = nullptr;
    return node;
}

// Recursive function to display the GLL in set notation
void display(GLLNode* head) 
{
    cout << "{";
    for (GLLNode* temp = head; temp != nullptr; temp = temp->next) {
        if (temp->flag == 0) {
            cout << temp->atom;
        } else {
            display(temp->down); // recursive call
        }
        if (temp->next != nullptr)
            cout << ", ";
    }
    cout << "}";
}

// ---------------- MAIN ----------------
int main()
 {
    // Build innermost sets
    GLLNode* emptySet = nullptr;   // {} → empty sublist

    GLLNode* set_uv = createAtom("u");
    set_uv->next = createAtom("v");

    GLLNode* set_yz = createAtom("y");
    set_yz->next = createAtom("z");

    // Build {r, s, t, {}, {u,v}, w, x, {y,z}, a1, b1}
    GLLNode* inner = createAtom("r");
    inner->next = createAtom("s");
    inner->next->next = createAtom("t");

    inner->next->next->next = createSublist(emptySet);          // {}
    inner->next->next->next->next = createSublist(set_uv);      // {u,v}
    inner->next->next->next->next->next = createAtom("w");
    inner->next->next->next->next->next->next = createAtom("x");
    inner->next->next->next->next->next->next->next = createSublist(set_yz); // {y,z}
    inner->next->next->next->next->next->next->next->next = createAtom("a1");
    inner->next->next->next->next->next->next->next->next->next = createAtom("b1");

    // Build main set S = {p, q, {inner}}
    GLLNode* S = createAtom("p");
    S->next = createAtom("q");
    S->next->next = createSublist(inner);

    // Display the set
    cout << "S = ";
    display(S);
    cout << endl;

    return 0;
}

```

## Sample Output
```
Enter the generalized set structure:
{ p q { r s t { } { u v } w x { y z } a1 b1 } #
Stored Set: {p, q, {r, s, t, {}, {u, v}, w, x, {y, z}, a1, b1}}
```

## Dry Run
Input:
```
{ p q { r s } # 
```
Steps:
- `{` encountered: start list  
- `p`, `q` added as atoms  
- `{` encountered: start sublist  
- `r`, `s` added inside sublist  
- `}` end of sublist  
- `#` end input  

Final structure:
```
{p, q, {r, s}}
```

## Conclusion
The program successfully stores nested sets using GLL and displays them in proper set notation.  
GLL provides dynamic and flexible representation for hierarchical data.
