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

Node* getIntersection(Node* headA, Node* headB) {
    if (!headA || !headB)
        return NULL;

    Node* pA = headA;
    Node* pB = headB;

    while (pA != pB) {
        if (pA == NULL)
            pA = headB;
        else
            pA = pA->next;

        if (pB == NULL)
            pB = headA;
        else
            pB = pB->next;
    }

    return pA; 
}


void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* common = new Node(30);
    common->next = new Node(40);
    common->next->next = new Node(50);

    Node* head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = common;

    Node* head2 = new Node(15);
    head2->next = common;

    cout << "List A: ";
    printList(head1);
    cout << "List B: ";
    printList(head2);

    Node* intersection = getIntersection(head1, head2);

    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}
