#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// Push to stack
void push(int value) {
    if (top < SIZE - 1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop from stack
int pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack Underflow\n");
        return -1;
    }
}

// Evaluate Postfix Expression
int evaluatePostfix(char* postfix) {
    int i, op1, op2, result;
    char ch;

    for (i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if (isdigit(ch)) {
            // Convert character to integer and push
            push(ch - '0');
        } else {
            // Pop two operands
            op2 = pop();
            op1 = pop();

            // Apply operation
            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '%': result = op1 % op2; break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return -1;
            }

            // Push result back
            push(result);
        }
    }

    // Final result
    return pop();
}

// Main function
int main() {
    char postfix[SIZE];

    printf("Enter postfix expression (single-digit operands): ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result of postfix expression: %d\n", result);

    return 0;
}

