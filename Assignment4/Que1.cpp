#include <iostream>
using namespace std;

#define MAX 100
int q[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX - 1) cout << "Queue full" << endl;
    else {
        if (front == -1) front = 0;
        q[++rear] = x;
    }
}

void dequeue() {
    if (front == -1) cout << "Queue empty" << endl;
    else {
        cout << "Removed: " << q[front] << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }
}

void peek() {
    if (front == -1) cout << "Queue empty" << endl;
    else cout << "Front element: " << q[front] << endl;
}

void display() {
    if (front == -1) cout << "Queue empty" << endl;
    else {
        cout << "Queue: ";
        for (int i = front; i <= rear; i++) cout << q[i] << " ";
        cout << endl;
    }
}

int main() {
    int ch, val;
    do {
        cout << "1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit: ";
        cin >> ch;
        switch (ch) {
            case 1: cin >> val; enqueue(val); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while (ch != 5);
    return 0;
}

