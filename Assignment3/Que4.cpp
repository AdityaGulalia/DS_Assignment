#include <iostream>
using namespace std;

#define MAX 100

char myStack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        myStack[++top] = c;
    }
}
char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return myStack[top--];
    }
}
char peek() {
    if (top == -1) return '\0';
    return myStack[top];
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop();
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

