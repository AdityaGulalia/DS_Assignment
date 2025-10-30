#include <iostream>
using namespace std;

class Stack {
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == 99) {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            return '\0'; 
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

};
// if the previous bracket matcher the next one which the the opposite if the previous then it has balanced parentheses
bool isBalanced(char exp[]) {
    Stack st;
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty()) {
                return false;  
            }
            char topChar = st.pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return st.isEmpty(); 
}

int main() {
    char expression[100];
    cout << "Enter an expression: ";
    cin >> expression; 

    if (isBalanced(expression))
        cout << "Balanced expression " << endl;
    else
        cout << "Unbalanced expression " << endl;

    return 0;
}
