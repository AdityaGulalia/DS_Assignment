#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool cycle = false;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cycle = true;
            break;
        }
    }

    if (!cycle) {
        cout << "No loop detected." << endl;
        return;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    Node* ptr = slow;
    while (ptr->next != slow) {
        ptr = ptr->next;
    }
    ptr->next = NULL; 
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next->next;
    printList(head);
    removeLoop(head);

    cout << "Linked List after removing loop: ";
    printList(head);

    return 0;
}
