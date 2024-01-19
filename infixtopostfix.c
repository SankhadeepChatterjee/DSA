#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j;
    char stack[MAX_SIZE];
    int top = -1;

    // Initialize the postfix string
    postfix[0] = '\0';

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (infix[i] == ' ' || infix[i] == '\t') {
            // Ignore spaces and tabs
            continue;
        } else if (isdigit(infix[i]) || isalpha(infix[i])) {
            // If operand, copy to postfix
            postfix[j++] = infix[i];
        } else if (isOperator(infix[i])) {
            // If operator, pop higher or equal precedence operators from the stack and then push the current operator
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        } else if (infix[i] == '(') {
            // If '(', push onto stack
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            // If ')', pop and append operators until '(' is encountered
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            // Pop '('
            top--;
        }
    }

    // Pop and append remaining operators from the stack
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    // Null-terminate the postfix expression
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    // Input infix expression
    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    // Convert infix to postfix
    infixToPostfix(infix, postfix);

    // Output postfix expression
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
