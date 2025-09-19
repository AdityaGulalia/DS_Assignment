#include <iostream>
using namespace std;

#define MAX 100

int charstack[MAX];
int top = -1;

void push(int val) {
    charstack[++top] = val;
}

int pop() {
    return charstack[top--];
}

bool isEmpty() {
    return top == -1;
}

int peek() {
    return charstack[top];
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int A[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "Nearest Smaller to Left: ";

    for (int i = 0; i < n; i++) {
        while (!isEmpty() && peek() >= A[i]) {
            pop();
        }

        if (isEmpty())
            cout << -1 << " ";
        else
            cout << peek() << " ";

        push(A[i]);
    }

    cout << endl;
    return 0;
}

