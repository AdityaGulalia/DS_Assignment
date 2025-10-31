#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next1 = NULL;

        while (current != NULL) {
            next1 = current->next;   
            current->next = prev;   
            prev = current;        
            current = next1;      
        }

        head = prev; 
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);

    cout << "Original List: ";
    list.display();

    list.reverse();

    cout << "Reversed List: ";
    list.display();

    return 0;
}
