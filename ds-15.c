#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

// Push operation
void push(char c) {
    if (top < SIZE - 1) {
        stack[++top] = c;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Pop operation
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        return '\0'; // Stack underflow
    }
}

// Peek top of stack
char peek() {
    if (top >= 0) return stack[top];
    else return '\0';
}

// Check if operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Get precedence
int precedence(char op) {
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
}

// Infix to Postfix conversion function
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char c;
    
    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(' && top != -1) {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        } else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Main function
int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

