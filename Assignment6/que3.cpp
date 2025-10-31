#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
    DNode* head;

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    int size() {
        int count = 0;
        DNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

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
        if (last == NULL) {
            last = newNode;
            last->next = last; 
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    int size() {
        if (last == NULL)
            return 0;

        int count = 0;
        CNode* temp = last->next;
        while (true) {
            count++;
            temp = temp->next;
            if (temp == last->next)
                break;
        }
        return count;
    }

    void display() {
        if (last == NULL) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }

        CNode* temp = last->next;
        cout << "Circular Linked List: ";
        while (true) {
            cout << temp->data << " ";
            temp = temp->next;
            if (temp == last->next)
                break;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dlist;
    CircularLinkedList clist;
    int choice, val;

    while (true) {
        cout << endl;
        cout << "1. Insert in Doubly Linked List" << endl;
        cout << "2. Display Doubly Linked List and Size" << endl;
        cout << "3. Insert in Circular Linked List" << endl;
        cout << "4. Display Circular Linked List and Size" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 5)
            break;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            dlist.insertAtBeginning(val);
        } else if (choice == 2) {
            dlist.display();
            cout << "Size of Doubly Linked List: " << dlist.size() << endl;
        } else if (choice == 3) {
            cout << "Enter value: ";
            cin >> val;
            clist.insertAtBeginning(val);
        } else if (choice == 4) {
            clist.display();
            cout << "Size of Circular Linked List: " << clist.size() << endl;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    cout << "Program exited." << endl;
    return 0;
}
