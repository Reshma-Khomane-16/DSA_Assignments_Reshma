# Assignment 1 — Basic String Operations Using Character Arrays (Student Generated)

## Title  
Basic String Operations (Length, Copy, Reverse, Concatenation)

## Objective  
To implement fundamental string operations such as length calculation, copying, reversing, and concatenation using character arrays **without using built‑in string functions**.

## Theory  
A string in C++ is represented as a character array ending with a null character `\0`.  
Basic operations on strings can be performed manually by iterating through the array:

- **Length Calculation:** Count characters until `\0` is reached.  
- **Copy:** Copy each character from source to destination until `\0`.  
- **Reverse:** Swap or rebuild the string from the end to the beginning.  
- **Concatenation:** Append characters of the second string to the end of the first.

These operations help understand how low‑level string manipulation works internally.

## Algorithm  

### 1. Find String Length  
1. Start counter = 0  
2. Loop through characters until `\0`  
3. Increment counter  
4. Return counter  

### 2. Copy String  
1. Loop through characters of source  
2. Copy each into destination  
3. Add `\0` to end  

### 3. Reverse String  
1. Find length  
2. Store characters from end to beginning into new array  
3. Add `\0`  

### 4. Concatenate Strings  
1. Move pointer to end of first string  
2. Copy characters of second string  
3. Add `\0`  

---

## Code (With Modified Function Names Using _srb)

```cpp
#include <iostream>
using namespace std;

int stringLength_srb(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy_srb(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0';
}

void stringReverse_srb(char str[], char reversed[]) {
    int length = stringLength_srb(str);
    int i;
    for (i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[i] = '\0';
}

void stringConcatenate_srb(char str1[], char str2[], char result[]) {
    int i = 0, j = 0;

    while (str1[i] != '\0') {
        result[i] = str1[i];
        i++;
    }

    while (str2[j] != '\0') {
        result[i] = str2[j];
        i++;
        j++;
    }

    result[i] = '\0';
}

int main() {
    char str1[100], str2[100];
    char copied[100], reversed[100], concatenated[200];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    cout << "\nLength of first string: " << stringLength_srb(str1);
    cout << "\nLength of second string: " << stringLength_srb(str2);

    stringCopy_srb(str1, copied);
    cout << "\n\nCopied first string: " << copied;

    stringReverse_srb(str1, reversed);
    cout << "\nReversed first string: " << reversed;

    stringConcatenate_srb(str1, str2, concatenated);
    cout << "\nConcatenated string: " << concatenated;

    return 0;
}
```

---

## Sample Output (Text Format)

```
Enter first string: hello
Enter second string: world

Length of first string: 5
Length of second string: 5

Copied first string: hello
Reversed first string: olleh
Concatenated string: helloworld
```
