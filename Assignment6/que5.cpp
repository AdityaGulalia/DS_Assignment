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

bool isCircular(Node* head) {
    if (head == NULL)
        return false;

    Node* temp = head->next;
    while (temp != NULL && temp != head)
        temp = temp->next;

    if (temp == head)
        return true;
    else
        return false;
}

int main() {
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n1;

    Node* head = n1;

    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;

    return 0;
}
