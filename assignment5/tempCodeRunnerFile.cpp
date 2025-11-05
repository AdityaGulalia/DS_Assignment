#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};

class list{
    public:
    node *head;
    node *tail;
    list(){
        head = NULL;
        tail = NULL;
    }
    void push_front(int val){
        node* newnode = new node(val);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;

        }
    }
    void push_back(int val ){
        node* newnode = new node(val);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
            newnode->next = NULL; 
        }
    }
    void pop_out(){
        if(head == NULL){
            return;
        }
        else{
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void pop_back(){
        if(tail == NULL){
            return;
        }
        else{
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
            
        }
    }
    void insert(int val, int pos){
        node* newnode = new node(val);
        if(pos < 0){
            cout<<"invalid"<<endl;
            return;
        }
        else if(pos == 0){
            push_front(val);
            return;
        }
        else {
            node* temp = head;
            for(int i=0; i<pos-1; i++){
                if(temp == NULL){
                    return;
                }
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    void delete_pos(int pos){
        if(pos < 0 || head == NULL){
            cout<<"invalid"<<endl;
            return;
        }
        else if(pos == 0){
            pop_out();
            return;
        }
        else{
            node* temp = head;
            for(int i=0 ;i<pos-1; i++){
                temp = temp->next;
            }
            node* todelete = temp->next;
            temp->next = temp->next->next;
            delete todelete;
        }
    }
    void search(int val){
        node* temp = head;
        int pos = 0;
        while(temp != tail){
            if(temp->data == val){
                cout<<"found at position "<<pos<<endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout<<"not found"<<endl;
    }
    void printll(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

node* reverse_K_node(int k, node* head){
    node* current = head;
    node* prev = NULL;
    node* next1 = NULL;
    int count = 0;
    if(head == NULL){
        return;
    }
    while(current != NULL && count < k){
        next1 = current->next;   
        current->next = prev;   
        prev = current;        
        current = next1;  
        count++;
    }
    if (next1 != NULL) {
        head->next = reverse_K_node(k , next1);
    }
    return prev;
}



int main(){
    list l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);
    l.printll();
    cout<<endl;
    reverse_K_node(3, l.head);
    l.printll();
    return 0;
}