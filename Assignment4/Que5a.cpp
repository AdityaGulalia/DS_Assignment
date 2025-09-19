#include <iostream>
using namespace std;

#define MAX 100
int q1[MAX], q2[MAX];
int f1=0,r1=-1,f2=0,r2=-1;

void push(int x) {
    q2[++r2] = x;
    while (f1 <= r1) q2[++r2] = q1[f1++];
    for (int i=0;i<=r2;i++) q1[i]=q2[i];
    r1=r2; f1=0; f2=0; r2=-1;
}

int pop() {
    if (f1 > r1) return -1;
    return q1[f1++];
}

int main() {
    push(10); push(20); push(30);
    cout << pop() << endl; 
    cout << pop() << endl; 
    return 0;
}

