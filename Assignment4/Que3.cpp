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

    public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) return -1;
        return front->data;
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int size() {
        int count = 0;
        Node* temp = front;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

void interleaveQueue(Queue &q) {
    int n = q.size();
    int half = n / 2;
    Queue firstHalf;

    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }

    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue());
        if (!q.isEmpty()) 
            q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;
    q.enqueue(4);
    q.enqueue(7);
    q.enqueue(11);
    q.enqueue(20);
    q.enqueue(5);
    q.enqueue(9);

    cout << "Original Queue: ";
    q.display();

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    q.display();

    return 0;
}
