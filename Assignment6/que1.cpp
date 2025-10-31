#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;
    DNode(int val) : data(val), prev(NULL), next(NULL) {}
};

class CNode {
public:
    int data;
    CNode* next;
    CNode(int val) : data(val), next(NULL) {}
};

class DoublyLinkedList {
    DNode* head;
public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val) {
        DNode* newNode = new DNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        DNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAfter(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found" << endl;
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
    }

    void insertBefore(int key, int val) {
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found" << endl;
            return;
        }
        DNode* newNode = new DNode(val);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev)
            temp->prev->next = newNode;
        else
            head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int key) {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        DNode* temp = head;
        while (temp && temp->data != key)
            temp = temp->next;
        if (!temp) {
            cout << "Node " << key << " not found" << endl;
            return;
        }
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        delete temp;
        cout << "Node " << key << " deleted" << endl;
    }

    void search(int key) {
        DNode* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
        }
        cout << "Node " << key << " not found" << endl;
    }

    void display() {
        DNode* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
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

    void insertAfter(int key, int val) {
        if (!last) {
            cout << "List is empty" << endl;
            return;
        }
        CNode* temp = last->next;
        while (true) {
            if (temp->data == key) {
                CNode* newNode = new CNode(val);
                newNode->next = temp->next;
                temp->next = newNode;
                if (temp == last)
                    last = newNode;
                return;
            }
            temp = temp->next;
            if (temp == last->next)
                break;
        }
        cout << "Node " << key << " not found" << endl;
    }

    void deleteNode(int key) {
        if (!last) {
            cout << "List is empty" << endl;
            return;
        }

        CNode* temp = last->next;
        CNode* prev = last;

        while (true) {
            if (temp->data == key) {
                if (temp == last && temp->next == last) {
                    last = NULL;
                } else {
                    prev->next = temp->next;
                    if (temp == last)
                        last = prev;
                }
                delete temp;
                cout << "Node " << key << " deleted" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
            if (temp == last->next)
                break;
        }
        cout << "Node " << key << " not found" << endl;
    }

    void search(int key) {
        if (!last) {
            cout << "List is empty" << endl;
            return;
        }
        CNode* temp = last->next;
        int pos = 1;
        while (true) {
            if (temp->data == key) {
                cout << "Node " << key << " found at position " << pos << endl;
                return;
            }
            pos++;
            temp = temp->next;
            if (temp == last->next)
                break;
        }
        cout << "Node " << key << " not found" << endl;
    }

    void display() {
        if (!last) {
            cout << "Circular Linked List is empty" << endl;
            return;
        }
        cout << "Circular Linked List: ";
        CNode* temp = last->next;
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
    int listType, choice, val, key;

    while (true) {
        cout << endl << "1. Doubly Linked List" << endl;
        cout << "2. Circular Linked List" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> listType;

        if (listType == 3) break;

        while (true) {
            cout << endl << "1. Insert at Beginning" << endl;
            cout << "2. Insert at End" << endl;
            cout << "3. Insert After a Node" << endl;
            if (listType == 1) cout << "4. Insert Before a Node" << endl;
            cout << "5. Delete a Node" << endl;
            cout << "6. Search a Node" << endl;
            cout << "7. Display List" << endl;
            cout << "8. Go Back" << endl;
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 8) break;

            cout << endl;
            if (listType == 1) { 
                if (choice == 1) { cout << "Enter value: "; cin >> val; dlist.insertAtBeginning(val); }
                else if (choice == 2) { cout << "Enter value: "; cin >> val; dlist.insertAtEnd(val); }
                else if (choice == 3) { cout << "Enter key and value: "; cin >> key >> val; dlist.insertAfter(key, val); }
                else if (choice == 4) { cout << "Enter key and value: "; cin >> key >> val; dlist.insertBefore(key, val); }
                else if (choice == 5) { cout << "Enter key: "; cin >> key; dlist.deleteNode(key); }
                else if (choice == 6) { cout << "Enter key: "; cin >> key; dlist.search(key); }
                else if (choice == 7) dlist.display();
            } 
            else if (listType == 2) { 
                if (choice == 1) { cout << "Enter value: "; cin >> val; clist.insertAtBeginning(val); }
                else if (choice == 2) { cout << "Enter value: "; cin >> val; clist.insertAtEnd(val); }
                else if (choice == 3) { cout << "Enter key and value: "; cin >> key >> val; clist.insertAfter(key, val); }
                else if (choice == 5) { cout << "Enter key: "; cin >> key; clist.deleteNode(key); }
                else if (choice == 6) { cout << "Enter key: "; cin >> key; clist.search(key); }
                else if (choice == 7) clist.display();
            }
        }
    }

    cout << "Program exited." << endl;
    return 0;
}