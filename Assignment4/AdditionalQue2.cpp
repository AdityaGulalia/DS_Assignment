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
    int count; 

public:
    Queue() {
        front = rear = NULL;
        count = 0;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    int dequeue() {
        if (isEmpty()) return -1;
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
        count--;
        return val;
    }

    int size() {
        return count;
    }

    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main(){
    return 0;
}
