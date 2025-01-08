#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int evaluatePrefix(char* expression) {
    for (int i = strlen(expression) - 1; i >= 0; i--) {
        if (isdigit(expression[i])) {
            push(expression[i] - '0');
        } else {
            int operand1 = pop();
            int operand2 = pop();
            switch (expression[i]) {
                case '+': push(operand1 + operand2); break;
                case '-': push(operand1 - operand2); break;
                case '*': push(operand1 * operand2); break;
                case '/': push(operand1 / operand2); break;
            }
        }
    }
    return pop();
}

int main() {
    printf("The result of prefix expression +9*26 is %d\n", evaluatePrefix("+9*26"));
    return 0;
}