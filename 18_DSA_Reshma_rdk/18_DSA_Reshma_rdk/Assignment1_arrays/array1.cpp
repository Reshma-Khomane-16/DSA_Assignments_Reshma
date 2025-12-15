/*Implement basic string operations such as length calculation, copy, reverse, and 
concatenation using character single dimensional arrays without using built-in string 
library functions.*/

#include <iostream>
using namespace std;

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; 
}
void stringReverse(char str[], char reversed[]) {
    int length = stringLength(str);
    int i;
    for (i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[i] = '\0'; 
}
void stringConcatenate(char str1[], char str2[], char result[]) {
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

    result[i] = '\0'; // Null terminator
}

int main() {
    char str1[100], str2[100];
    char copied[100], reversed[100], concatenated[200];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    // Length
    cout << "\nLength of first string: " << stringLength(str1);
    cout << "\nLength of second string: " << stringLength(str2);

    // Copy
    stringCopy(str1, copied);
    cout << "\n\nCopied first string: " << copied;

    // Reverse
    stringReverse(str1, reversed);
    cout << "\nReversed first string: " << reversed;

    // Concatenate
    stringConcatenate(str1, str2, concatenated);
    cout << "\nConcatenated string: " << concatenated;

    return 0;
}
