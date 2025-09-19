#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node(); newNode->data = val; newNode->next = NULL;
    if(head==NULL) head = newNode;
    else { Node* temp=head; while(temp->next!=NULL) temp=temp->next; temp->next=newNode; }
}

int countAndDelete(int key) {
    int count = 0;
    while(head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp; count++;
    }
    Node* temp = head;
    while(temp != NULL && temp->next != NULL) {
        if(temp->next->data == key) {
            Node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else temp = temp->next;
    }
    return count;
}

void displayList() {
    Node* temp=head;
    while(temp!=NULL) { cout<<temp->data<<"->"; temp=temp->next; }
    cout<<"NULL"<<endl;
}

int main() {
    int arr[]={1,2,1,2,1,3,1}, key=1;
    for(int i=0;i<7;i++) insertAtEnd(arr[i]);
    int cnt = countAndDelete(key);
    cout<<"Count: "<<cnt<<endl;
    cout<<"Updated List: "; displayList();
    return 0;
}

