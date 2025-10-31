#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* prev;
    Node* next;
    Node(char val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;
    Node* start = head;
    Node* end = head;
    while (end->next != NULL)
        end = end->next;
    while (start != end && end->next != start) {
        if (start->data != end->data)
            return false;
        start = start->next;
        end = end->prev;
    }

    return true;
}

int main() {
    Node* n1 = new Node('r');
    Node* n2 = new Node('a');
    Node* n3 = new Node('d');
    Node* n4 = new Node('a');
    Node* n5 = new Node('r');
    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;
    n3->next = n4;
    n4->prev = n3;
    n4->next = n5;
    n5->prev = n4;

    Node* head = n1;

    if (isPalindrome(head))
        cout << "The doubly linked list is a palindrome." << endl;
    else
        cout << "The doubly linked list is not a palindrome." << endl;

    return 0;
}
