#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
    Node* front;
    Node* rear;
    int length;  

public:
    Queue() {
        front = rear = NULL;
        length = 0;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        length++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (!front) rear = NULL;
        delete temp;
        length--;
        return val;
    }

    int frontElement() {
        if (isEmpty()) return -1;
        return front->data;
    }

    int size() { return length; }

    void display() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Stack {
    Queue q;

public:
    void push(int x) {
        q.enqueue(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            int val = q.dequeue();
            q.enqueue(val);
        }
    }

    void pop() {
        if (q.isEmpty()) {
            return;
        }
        q.dequeue();
    }

    int top() {
        if (q.isEmpty()) {
            return -1;
        }
        return q.frontElement();
    }

    bool isEmpty() {
        return q.isEmpty();
    }

    void display() {
        cout << "Stack elements (top to bottom): ";
        q.display();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;
    s.display();

    s.pop();
    cout << "After pop, top: " << s.top() << endl;
    s.display();

    return 0;
}
