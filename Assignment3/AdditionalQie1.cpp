#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top < 99)
            arr[++top] = x;
    }

    void pop() {
        if (top >= 0)
            top--;
    }

    int peek() {
        if (top >= 0)
            return arr[top];
        return -1; 
    }

    bool isEmpty() {
        return top == -1;
    }
};

// we are starting from left and movving toward right and checking wether the element tp the left is smaller or not or not 
// if smaller then we are storing it otherwise popping the elements until we find a greater element or stack becomes empty
void nearestSmaller(int arr[], int n, int result[]) {
    Stack st;

    for (int i = 0; i < n; i++) {
        while (!st.isEmpty() && st.peek() >= arr[i]) {
            st.pop();
        }

        if (st.isEmpty())
            result[i] = -1;
        else
            result[i] = st.peek();

        st.push(arr[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;
    int result[5];

    nearestSmaller(arr, n, result);

    cout << "Nearest smaller elements: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
