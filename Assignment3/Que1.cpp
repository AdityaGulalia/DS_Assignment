#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 5

int stackArray[MAX];
int top = -1;
bool isEmpty() {
    return (top == -1);
}
bool isFull() {
    return (top == MAX - 1);
}
void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        stackArray[++top] = value;
        cout << value << " pushed to stack" << endl;
    }
}
void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow! Cannot pop" << endl;
    } else {
        cout << stackArray[top--] << " popped from stack" << endl;
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Stack is empty! No top element" << endl;
    } else {
        cout << "Top element is: " << stackArray[top] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements are:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << stackArray[i] << endl;
        }
    }
}
int main() {
    int choice, value;

    while (true) {
        cout << endl << "--- Stack Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check if Empty" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty())
                    cout << "Stack is Empty" << endl;
                else
                    cout << "Stack is Not Empty" << endl;
                break;
            case 4:
                if (isFull())
                    cout << "Stack is Full" << endl;
                else
                    cout << "Stack is Not Full" << endl;
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                exit(0);
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
