#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;
void insertAtBeginning(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}
void insertBeforeAfter(int val, int target, bool after) {
    if (head == NULL) return;
    Node* newNode = new Node();
    newNode->data = val;

    Node* temp = head;
    if (after) {
        while (temp != NULL && temp->data != target) temp = temp->next;
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else cout << "Target not found!\n";
    } else { 
        if (head->data == target) {
            newNode->next = head;
            head = newNode;
            return;
        }
        while (temp->next != NULL && temp->next->data != target) temp = temp->next;
        if (temp->next != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else cout << "Target not found!\n";
    }
}
void deleteBeginning() {
    if (head == NULL) { cout << "List is empty!\n"; return; }
    Node* temp = head;
    head = head->next;
    delete temp;
}
void deleteEnd() {
    if (head == NULL) { cout << "List is empty!\n"; return; }
    if (head->next == NULL) { delete head; head = NULL; return; }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}
void deleteNode(int key) {
    if (head == NULL) { cout << "List is empty!\n"; return; }
    if (head->data == key) { deleteBeginning(); return; }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != key) temp = temp->next;
    if (temp->next != NULL) {
        Node* del = temp->next;
        temp->next = temp->next->next;
        delete del;
    } else cout << "Node not found!\n";
}
int searchNode(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == key) return pos;
        temp = temp->next;
        pos++;
    }
    return -1; 
}
void displayList() {
    if (head == NULL) { cout << "List is empty!\n"; return; }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int choice, val, target, after;

    while (true) {
        cout << "\nMenu:\n1.Insert at Beginning\n2.Insert at End\n3.Insert before/after\n4.Delete Beginning\n5.Delete End\n6.Delete Node\n7.Search Node\n8.Display\n9.Exit\n";
        cout << "Enter your choice: ";
        
        if (!(cin >> choice)) {          
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Enter a number between 1-9.\n";
            continue;
        }

        if (choice == 9) break; 

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            insertAtBeginning(val);
        } 
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            insertAtEnd(val);
        } 
        else if (choice == 3) {
            cout << "Enter value, target, after(1-after,0-before): ";
            cin >> val >> target >> after;
            insertBeforeAfter(val, target, after);
        } 
        else if (choice == 4) {
            deleteBeginning();
        } 
        else if (choice == 5) {
            deleteEnd();
        } 
        else if (choice == 6) {
            cout << "Enter value to delete: ";
            cin >> val;
            deleteNode(val);
        } 
        else if (choice == 7) {
            cout << "Enter value to search: ";
            cin >> val;
            int pos = searchNode(val);
            if (pos == -1) cout << "Node not found!\n";
            else cout << "Node found at position: " << pos << endl;
        } 
        else if (choice == 8) {
            displayList();
        } 
        else {
            cout << "Invalid choice! Enter 1-9."<<endl;
        }
    }

    cout << "Exiting program."<<endl;
    return 0;
}

