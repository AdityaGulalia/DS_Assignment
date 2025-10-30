#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char val) {
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

    void enqueue(char val) {
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (isEmpty()) return;
        Node* temp = front;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete temp;
    }

    char getFront() {
        if (isEmpty()) return '\0';
        return front->data;
    }
};

void firstNonRepeating(string str) {
    int freq[26] = {0}; 
    Queue q;

    for (char ch : str) {
        freq[ch - 'a']++;
        q.enqueue(ch);
        while (!q.isEmpty() && freq[q.getFront() - 'a'] > 1) {
            q.dequeue();
        }
        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.getFront() << " ";
    }
}

int main() {
    string input;
    cout << "Enter the stream of characters: ";
    getline(cin, input);

    cout << "Output: ";
    firstNonRepeating(input);
    cout << endl;

    return 0;
}
