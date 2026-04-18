#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if brackets match
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check balanced expression
int isBalanced(char* s) {
    int n = strlen(s);
    char* stack = (char*)malloc(n * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {
        char ch = s[i];

        // Opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // Closing brackets
        else {
            if (top == -1) return 0; // no matching opening

            if (isMatchingPair(stack[top], ch)) {
                top--; // pop
            } else {
                return 0;
            }
        }
    }

    // If stack is empty → balanced
    return (top == -1);
}

int main() {
    char s[100000];

    // Your details
    printf("Name: Siddhi Timkhede\n");
    printf("PRN: 25070521236\n");
    printf("Batch: D-2\n\n");

    printf("Enter expression: ");
    scanf("%s", s);

    if (isBalanced(s))
        printf("Balanced Expression\n");
    else
        printf("Not Balanced Expression\n");

    return 0;
}
