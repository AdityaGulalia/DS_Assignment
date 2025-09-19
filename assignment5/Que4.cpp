#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head=NULL;

void insertAtEnd(int val) {
    Node* newNode=new Node(); newNode->data=val; newNode->next=NULL;
    if(head==NULL) head=newNode;
    else { Node* temp=head; while(temp->next!=NULL) temp=temp->next; temp->next=newNode; }
}

void reverseList() {
    Node* prev=NULL; Node* curr=head; Node* next;
    while(curr!=NULL) { next=curr->next; curr->next=prev; prev=curr; curr=next; }
    head=prev;
}

void displayList() {
    Node* temp=head;
    while(temp!=NULL) { cout<<temp->data<<"->"; temp=temp->next; }
    cout<<"NULL"<<endl;
}

int main() {
    int arr[]={1,2,3,4};
    for(int i=0;i<4;i++) insertAtEnd(arr[i]);
    reverseList();
    displayList();
    return 0;
}

