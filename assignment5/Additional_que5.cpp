#include<iostream>
using namespace std;

class node{
    public:
    int data;
    int power;
    node* next;
    node(int val, int pwr){
        data = val;
        power = pwr;
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
    void push_front(int val, int pwr){
        node* newnode = new node(val, pwr);
        if(head == NULL){
            head = newnode;
            tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;

        }
    }
    void push_back(int val, int pwr){
        node* newnode = new node(val, pwr);
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
    void insert(int val, int pos, int pwr){
        node* newnode = new node(val, pwr);
        if(pos < 0){
            cout<<"invalid"<<endl;
            return;
        }
        else if(pos == 0){
            push_front(val, pwr);
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
    void search(int val, int pwr){
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

    void printList(node* head) {
    node* curr = head;

    while (curr != nullptr) {
        cout << curr->data << "," << curr->power <<" ";
        curr = curr->next;
    }
    
    cout<<endl;
}
};

node* add_ll(node* head1, node* head2){
    node* p1 = head1;
    node* p2 = head2;
    list result;
    while(p1 != NULL && p2 != NULL){
        if(p1->power == p2->power){
            int sum = p1->data + p2->data;
            result.push_back(sum, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->power > p2->power){
            result.push_back(p1->data, p1->power);
            p1 = p1->next;
        }
        else{
            result.push_back(p2->data, p2->power);
            p2 = p2->next;
        }
    }
    return result.head;
}


int main(){
    list l1;
    l1.push_back(3, 3);
    l1.push_back(2, 2);
    l1.push_back(5, 0);
    list l2;
    l2.push_back(4, 3);
    l2.push_back(2, 1);
    l2.push_back(6, 0);
    node* result = add_ll(l1.head, l2.head);
    node* temp = result;
    l1.printList(temp);
    return 0;
}