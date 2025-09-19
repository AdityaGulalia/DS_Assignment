#include <iostream>
using namespace std;

#define MAX 100

long long myStack[MAX];
int top = -1;
long long minElement;

void push(int x) {
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
        return;
    }

    if (top == -1) { 
        top++;
        myStack[top] = x;
        minElement = x;
    }
    else if (x >= minElement) {
        myStack[++top] = x;
    }
    else { 
        myStack[++top] = 2LL * x - minElement;
        minElement = x;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
        return;
    }

    long long t = myStack[top--];

    if (t < minElement) {
        minElement = 2 * minElement - t;
    }
}
int topElement() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return -1;
    }

    long long t = myStack[top];
    if (t >= minElement) return (int)t;
    else return (int)minElement; 
}
int getMin() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return (int)minElement;
}
int main() {
    push(5);
    push(3);
    push(7);
    push(2);

    cout << "Current Min: " << getMin() << endl; 
    pop();
    cout << "Current Min: " << getMin() << endl; 
    pop();
    cout << "Top element: " << topElement() << endl; 
    cout << "Current Min: " << getMin() << endl; 
    return 0;
}

