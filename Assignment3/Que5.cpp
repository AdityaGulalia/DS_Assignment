#include <iostream>
using namespace std;

#define MAX 100

int charstack[MAX];
int top = -1;

void push(int value) {
    charstack[++top] = value;
}

int pop() {
    return charstack[top--];
}

int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (ch >= '0' && ch <= '9') {
            push(ch - '0');  
        } else {
            int b = pop();
            int a = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    cout << "Enter postfix expression: ";
    cin >> postfix;

    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}

