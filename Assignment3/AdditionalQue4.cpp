#include <iostream>
using namespace std;

#define MAX 100

int mystack[MAX];  
int top = -1;

void push(int x) {
    mystack[++top] = x;
}

int pop() {
    return mystack[top--];
}

bool isEmpty() {
    return top == -1;
}

int peek() {
    return mystack[top];
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temp[n], ans[n];
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
        ans[i] = 0; 
    }

    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && temp[peek()] <= temp[i]) {
            pop();
        }

        if (!isEmpty()) {
            ans[i] = peek() - i;
        }

        push(i);
    }

    cout << "Answer: ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

