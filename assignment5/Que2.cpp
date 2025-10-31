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
    LinkedList() { head = NULL; }

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

    int deleteKey(int key) {
        Node* temp = head;
        Node* prev = NULL;
        int count = 0;

        while (temp != NULL) {
            if (temp->data == key) {
                count++;
                Node* toDelete = temp;

                if (temp == head)
                    head = head->next;
                else
                    prev->next = temp->next;

                temp = temp->next;
                delete toDelete;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return count;
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(1);
    list.insertAtEnd(3);
    list.insertAtEnd(1);

    cout << "Original List: ";
    list.display();

    int key = 1;
    int count = list.deleteKey(key);

    cout << "Count: " << count << endl;
    cout << "Updated List: ";
    list.display();

    return 0;
}
