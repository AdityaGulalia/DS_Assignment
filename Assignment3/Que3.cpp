#include <iostream>
using namespace std;

#define MAX 100

char charStack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        charStack[++top] = c;
    }
}

// Pop operation
char pop() {
    if (top == -1) {
        return '\0'; 
    } else {
        return charStack[top--];
    }
}
bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}
bool isBalanced(char exp[]) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) { 
                return false;
            }
            char popped = pop();
            if (!isMatchingPair(popped, ch)) {
                return false;
            }
        }
    }
    return (top == -1);
}

int main() {
    char expression[MAX];

    cout << "Enter an expression: ";
    cin >> expression;

    if (isBalanced(expression)) {
        cout << "Expression has Balanced Parentheses" << endl;
    } else {
        cout << "Expression has Unbalanced Parentheses" << endl;
    }

    return 0;
}

