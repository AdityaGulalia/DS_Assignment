#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int x) {
    stackArr[++top] = x;
}

int pop() {
    return stackArr[top--];
}

bool isEmpty() {
    return top == -1;
}

int peek() {
    return stackArr[top];
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[n];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int expected = 1; 
    top = -1; 

    for (int i = 0; i < n; i++) {
        push(A[i]);

        while (!isEmpty() && peek() == expected) {
            pop();
            expected++;
        }
    }

    while (!isEmpty() && peek() == expected) {
        pop();
        expected++;
    }

    if (expected == n + 1)
        cout << "YES, it is possible to sort into B" << endl;
    else
        cout << "NO, it is not possible" << endl;

    return 0;
}

