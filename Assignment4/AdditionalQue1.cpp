#include <iostream>
#include <string>
using namespace std;

class Queue {
    string arr[100];
    int front, rear;
    int capacity, count;

public:
    Queue(int cap = 100) {
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

    void enqueue(string val) {
        if (isFull()) return;
        arr[++rear] = val;
        count++;
    }

    string dequeue() {
        if (isEmpty()) return "";
        return arr[front++];
        count--;
    }
};

void generateBinaryNumbers(int n) {
    Queue q;
    q.enqueue("1");

    for (int i = 1; i <= n; i++) {
        string curr = q.dequeue();
        cout << curr << " ";
        q.enqueue(curr + "0");
        q.enqueue(curr + "1");
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinaryNumbers(n);

    return 0;
}
