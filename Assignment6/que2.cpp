#include <iostream>
using namespace std;

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) : data(val), next(NULL) {}
};

class CircularLinkedList {
    CNode* last;

public:
    CircularLinkedList() : last(NULL) {}

    void insertAtBeginning(int val) {
        CNode* newNode = new CNode(val);
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        CNode* newNode = new CNode(val);
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void displayWithHeadRepeat() {
        if (!last) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }

        CNode* head = last->next;
        CNode* temp = head;

        cout << "Circular Linked List (head repeated): ";
        while (true) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == head)
                break;
        }
        cout << head->data << endl; 
    }
};

int main() {
    CircularLinkedList clist;
    int choice, val, key;

    while (true) {
        cout << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Display List with Head Repeated" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7)
            break;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            clist.insertAtBeginning(val);
        } else if (choice == 2) {
            clist.displayWithHeadRepeat();
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    cout << "Program exited." << endl;
    return 0;
}
