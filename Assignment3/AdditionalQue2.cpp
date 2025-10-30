#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    int minElement;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == 99) {
            cout << "Stack Overflow";
            return;
        }

        if (top == -1) {
            arr[++top] = x;
            minElement = x;
        } else if (x >= minElement) {
            arr[++top] = x;
        } else {
            arr[++top] = 2 * x - minElement;
            minElement = x;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow";
            return;
        }

        int t = arr[top--];

        if (t < minElement) {
            int oldMin = 2 * minElement - t;
            minElement = oldMin;
        }
    }

    int getMin() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minElement;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        int t = arr[top];
        if (t < minElement)
            return minElement; 
        return t;
    }
};

int main() {
    Stack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Current Min: " << st.getMin() << endl;

    st.pop();
    cout << "Current Min after one pop: " << st.getMin() << endl;

    st.pop();
    cout << "Current Min after another pop: " << st.getMin() << endl;

    cout << "Top element: " << st.peek() << endl;

    return 0;
}

