#include <iostream>
using namespace std;

class Queue {
    int arr[100];
    int front, rear, capacity;

public:
    Queue(int cap = 100) {
        capacity = cap;
        front = 0;
        rear = -1;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(int val) {
        if (isFull()) {
            return;
        }
        arr[++rear] = val;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front++];
    }

    int frontElement() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int size() {
        return rear - front + 1;
    }

    void reset() {  
        if (isEmpty()) {
            front = 0;
            rear = -1;
        }
    }
};

class Stack {
    Queue q1, q2;

public:
    void push(int x) {
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        q1.enqueue(x);

        while (!q2.isEmpty()) {
            q1.enqueue(q2.dequeue());
        }
    }

    void pop() {
        if (q1.isEmpty()) {
            return;
        }
        q1.dequeue();
    }

    int top() {
        if (q1.isEmpty()) {
            return -1;
        }
        return q1.frontElement();
    }

    bool isEmpty() {
        return q1.isEmpty();
    }

    void display() {
        if (q1.isEmpty()) {
            return;
        }

        cout << "Stack elements: ";
        for (int i = q1.frontElement(); i <= q1.size(); i++) {
            cout << q1.frontElement() << " ";
            q1.dequeue();
        }
        cout << endl;
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl; 
    s.push(40);
    cout << "Top after push 40: " << s.top() << endl; 
    return 0;
}
