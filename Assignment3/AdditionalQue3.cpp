#include <iostream>
using namespace std;

#define MAX 100

int AStack[MAX];
int top = -1;

void push(int x) {
    AStack[++top] = x;
}

int pop() {
    return AStack[top--];
}

bool isEmpty() {
    return top == -1;
}

int peek() {
    return AStack[top];
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n], nge[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && peek() <= arr[i]) {
            pop();
        }

        if (isEmpty())
            nge[i] = -1;
        else
            nge[i] = peek();

        push(arr[i]);
    }

    cout << "Next Greater Elements: ";
    for (int i = 0; i < n; i++) {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}

