#include <iostream>
using namespace std;

#define MAX 5
int cq[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        cout << "Queue full" << endl;
    } else {
        if (front == -1) front = rear = 0;
        else if (rear == MAX - 1) rear = 0;
        else rear++;
        cq[rear] = x;
    }
}

void dequeue() {
    if (front == -1) cout << "Queue empty" << endl;
    else {
        cout << "Removed: " << cq[front] << endl;
        if (front == rear) front = rear = -1;
        else if (front == MAX - 1) front = 0;
        else front++;
    }
}

void display() {
    if (front == -1) cout << "Queue empty" << endl;
    else {
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << cq[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

void peek() {
    if (front == -1) cout << "Queue empty" << endl;
    else cout << "Front: " << cq[front] << endl;
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

