#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
Node* head=NULL;

void insertAtEnd(int val) {
    Node* newNode=new Node(); newNode->data=val; newNode->next=NULL;
    if(head==NULL) head=newNode;
    else { Node* temp=head; while(temp->next!=NULL) temp=temp->next; temp->next=newNode; }
}

int findMiddle() {
    Node* slow=head; Node* fast=head;
    while(fast!=NULL && fast->next!=NULL) { slow=slow->next; fast=fast->next->next; }
    return slow->data;
}

int main() {
    int arr[]={1,2,3,4,5};
    for(int i=0;i<5;i++) insertAtEnd(arr[i]);
    cout<<"Middle: "<<findMiddle()<<endl;
    return 0;
}

