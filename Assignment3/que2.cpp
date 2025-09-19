#include <iostream>
using namespace std;

#define MAX 100

char charStack[MAX];
int top = -1;
bool isEmpty() {
    return (top == -1);
}
bool isFull() {
    return (top == MAX - 1);
}
void push(char c) {
    if (isFull()) {
        cout << "Stack Overflow! Cannot push " << c << endl;
    } else {
        charStack[++top] = c;
    }
}
char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    } else {
        return charStack[top--];
    }
}

int findLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[MAX];

    cout << "Enter a string: ";
    cin >> str;  

    int len = findLength(str);
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    cout << "Reversed string: ";
    while (!isEmpty()) {
        cout << pop();
    }
    cout << endl;

    return 0;
}

