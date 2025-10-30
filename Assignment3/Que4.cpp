#include <iostream>
using namespace std;

class Stack {
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == 99) return;
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) return '\0';
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
// this function works on the basics of that the operators with higher precedence 
// are placed before the operators with lower precedence in the postfix expression.
void infixToPostfix(char infix[]) {
    Stack st;
    char postfix[100];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            postfix[j++] = ch;
        }

        else if (ch == '(') {
            st.push(ch);
        }

        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix[j++] = st.pop();
            }
            st.pop(); 
        }

        else if (isOperator(ch)) {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix[j++] = st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty()) {
        postfix[j++] = st.pop();
    }

    postfix[j] = '\0';
    cout << "Postfix expression: " << postfix << endl;
}

int main() {
    char infix[100];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix);
    return 0;
}
