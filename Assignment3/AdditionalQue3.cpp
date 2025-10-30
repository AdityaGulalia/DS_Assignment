#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == 99) return;
        arr[++top] = x;
    }

    void pop() {
        if (top != -1)
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
// we are starting from right and movving toward left and checking wether the element tp the right is greater or not 
// if greater we are storing it otherwise popping the elements until we find a greater element or stack becomes empty
void findNextGreater(int arr[], int n, int nge[]) {
    Stack st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.isEmpty() && st.peek() <= arr[i]) {
            st.pop();
        }

        if (st.isEmpty()){
            nge[i] = -1;
            }
        else{
            nge[i] = st.peek();
        }
        st.push(arr[i]);
    }
}

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = 4;
    int nge[100];

    findNextGreater(arr, n, nge);

    cout << "Element Next Greater";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " " << nge[i] << endl;
    }

    return 0;
}
