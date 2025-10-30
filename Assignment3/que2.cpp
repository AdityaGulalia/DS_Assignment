#include <iostream>
using namespace std;

class Stack {
    char arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    char s[100];
    cout << "Enter a string: ";
    cin >> s;  

    Stack st;

    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len; i++) {
        st.push(s[i]);
    }

    cout << "Reversed string: ";
    while (!st.isEmpty()) {
        cout << st.pop();
    }

    cout << endl;
    return 0;
}
