#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
public:
    Stack() { top = -1; }

    void push(int value) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return 0;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};
// If operand push to stack.
// If operator pop top 2 operands, perform the operation, and push the result back.
int evaluatePostfix(string exp) {
    Stack st;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0');  
        }

        else {
            int val2 = st.pop();
            int val1 = st.pop();
            int result = 0;

            if (ch == '+')
                result = val1 + val2;
            else if (ch == '-')
                result = val1 - val2;
            else if (ch == '*')
                result = val1 * val2;
            else if (ch == '/')
                result = val1 / val2;

            st.push(result);
        }
    }

    return st.pop();
}

int main() {
    string postfix;
    cout << "Enter Postfix expression: ";
    cin >> postfix;   
    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}
