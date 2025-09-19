#include <iostream>
using namespace std;

#define MAX 100
int q[MAX]; int f=0,r=-1;

void push(int x) {
    q[++r] = x;
    for (int i = 0; i < r; i++) {
        q[++r] = q[f++];
    }
}

int pop() {
    if (f > r) return -1;
    return q[f++];
}

int main() {
    push(10); push(20); push(30);
    cout << pop() << endl; 
    cout << pop() << endl; 
    return 0;
}

