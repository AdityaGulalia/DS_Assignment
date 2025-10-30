#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(int val) {
        if (top == 99) {
            cout << "Stack Overflow";
            return;
        }
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow";
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1)
            return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool canBeSorted(int A[], int n) {
    Stack st;
    int expected = 1; 
    int i = 0;

    while (i < n) {
        st.push(A[i]);

        while (!st.isEmpty() && st.peek() == expected) {
            st.pop();
            expected++;
        }
        i++;
    }

    while (!st.isEmpty() && st.peek() == expected) {
        st.pop();
        expected++;
    }

    return (st.isEmpty());
}

int main() {
    int A[] = {60,50,55};
    int n = 3;

    if (canBeSorted(A, n))
        cout << "YES, array B can be sorted ascendingly.";
    else
        cout << "NO, array B cannot be sorted.";

    return 0;
}
