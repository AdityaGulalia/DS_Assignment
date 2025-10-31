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

    Node* findMiddle() {
        int count = 0;
        int pos_even = 0, pos_odd = 0;
        Node* temp = head;
        Node* temp_new = head;

        while (temp != NULL) {
            temp = temp->next;
            count++;
        }

        if (count % 2 == 0) {
            pos_even = count / 2;
            for (int i = 1; i <= pos_even; i++) {
                temp_new = temp_new->next;
            }
        } 
        else {
            pos_odd = count / 2;
            for (int i = 1; i <= pos_odd; i++) {
                temp_new = temp_new->next;
            }
        }

        return temp_new;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        }
    }

    void printMiddle() {
        Node* mid = findMiddle();
        if (mid)
            cout << "Middle element: " << mid->data << endl;
        else
            cout << "List is empty." << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);

    cout << "Linked List: ";
    list.display();

    list.printMiddle();

    return 0;
}
