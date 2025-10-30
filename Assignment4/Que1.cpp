#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* front;   
    Node* rear;    
    int count;     
    int capacity;  

public:
    Queue(int cap = 5) {
        front = NULL;
        rear = NULL;
        count = 0;
        capacity = cap;
    }

    bool isEmpty() {
        return (count == 0);
    }

    bool isFull() {
        return (count == capacity);
    }

    void enqueue(int value) {
        if (isFull()) {
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) {  
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }

        Node* temp = front;

        front = front->next;
        if (front == NULL)
            rear = NULL;

        delete temp;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            return;
        }
        cout << "Front element: " << front->data << endl;
    }

    void display() {
        if (isEmpty()) {
            return;
        }

        cout << "Queue elements: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int cap;
    cout << "Enter queue capacity: ";
    cin >> cap;

    Queue q(cap);
    int choice, value;

    while (true) {
        cout << "QUEUE MENU" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
                break;

            case 5:
                if (q.isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;

            case 6:
                if (q.isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                break;

            case 7:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
