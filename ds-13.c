#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define SIZE 100

// Stack for characters (for operators during conversion)
char stack[SIZE];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Infix to Postfix Conversion
void infixToPostfix(char* infix, char* postfix) {
    int i, j = 0;
    char ch;

    for(i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if(isdigit(ch)) {
            postfix[j++] = ch;
        } else if(ch == '(') {
            push(ch);
        } else if(ch == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } else if(isOperator(ch)) {
            while(!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    while(!isEmpty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Stack for Evaluation
int evalStack[SIZE];
int evalTop = -1;

void evalPush(int item) {
    evalStack[++evalTop] = item;
}

int evalPop() {
    return evalStack[evalTop--];
}

// Evaluate Postfix Expression
int evaluatePostfix(char* postfix) {
    int i, op1, op2, result;
    char ch;

    for(i = 0; postfix[i] != '\0'; i++) {
        ch = postfix[i];

        if(isdigit(ch)) {
            evalPush(ch - '0'); // convert char to int
        } else {
            op2 = evalPop();
            op1 = evalPop();

            switch(ch) {
                case '+': evalPush(op1 + op2); break;
                case '-': evalPush(op1 - op2); break;
                case '*': evalPush(op1 * op2); break;
                case '/': evalPush(op1 / op2); break;
                case '^': evalPush((int)pow(op1, op2)); break;
            }
        }
    }
    return evalPop();
}

// Main Function
int main() {
    char infix[SIZE], postfix[SIZE];

    printf("Enter Infix Expression (single digits only): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n", evaluatePostfix(postfix));

    return 0;
}

