#include <iostream>
using namespace std;

class Stack {
    int arr[100];
    int top;
    public:
    Stack() { top = -1; }

    void push(int val) {
        if (top == 99) return;
        arr[++top] = val;
    }

    void pop() {
        if (top == -1) return;
        top--;
    }

    int peek() {
        if (top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void dailyTemperatures(int temp[], int n, int ans[]) {
    Stack st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.isEmpty() && temp[st.peek()] <= temp[i])
            st.pop();

        if (st.isEmpty())
            ans[i] = 0;
        else
            ans[i] = st.peek() - i;

        st.push(i);
    }
}

int main() {
    int temp[] = {30, 40, 35, 50, 45, 60};
    int n = sizeof(temp) / sizeof(temp[0]);
    int ans[100];

    dailyTemperatures(temp, n, ans);

    cout << "Days until warmer temperature: ";
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;

    return 0;
}
