#include <iostream>
using namespace std;

class CircularQueue {
    int arr[100];       
    int front, rear;
    int count;
    int capacity;

public:
    CircularQueue(int cap = 100) { 
        capacity = cap;
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int x) {
        if (isFull()) {
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
    }

    void dequeue() {
        if (isEmpty()) {
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);
    int choice, val;

    while (true) {
        cout << "QUEUE MENU"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Peek"<<endl;
        cout << "4. Display"<<endl;
        cout << "5. Check if Empty"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        if (cin.fail()) { 
            cin.clear();  
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter a number"<<endl;
            continue;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
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
                    cout << "Queue is empty";
                else
                    cout << "Queue is not empty";
                break;

            case 6:
                cout << "Exiting program";
                return 0;

            default:
                cout << "Invalid choice! Try again";
        }
    }

    return 0;
}
}
