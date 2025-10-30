#include <iostream>
#include <vector>
using namespace std;

class Stack {
    private:
    int arr[100];
    int top;
    int maxsize;
    public:

    Stack(int size){
        top = -1;
        maxsize = size;
    }
    void push(int val){
        if(top == maxsize - 1){
            cout<<"overflow"<<endl;
            return;
        }
        else{
            ++top;
            arr[top] = val;
            return;
        }
    }
    void pop(){
        if(top == -1){
            cout<<"underflow"<<endl;
        }
        else{
            top--;
        }
    }
    bool is_empty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
    bool if_full(){
        if(top == maxsize - 1){
            return true;
        }
        else{
            return false;
        }
    }
    int peek(){
        if(top == -1){
            cout<<"stack is empty"<<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    void display(){
        for(int i=top; i>=0; i--){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    cout<<endl;
    s.pop();
    s.display();
    cout<<endl;
    cout<<"top element is "<<s.peek()<<endl;
    return 0;
}
