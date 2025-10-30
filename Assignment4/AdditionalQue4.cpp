#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudents(queue<int> students, stack<int> sandwiches) {
    int rotations = 0;  

    while (!students.empty()) {
        if (students.front() == sandwiches.top()) {
            students.pop();        
            sandwiches.pop();      
            rotations = 0;        
        } else {
            int stu = students.front();
            students.pop();
            students.push(stu);    
            rotations++;          
        }

        if (rotations == students.size()) break;
    }

    return students.size(); 
}

int main() {
    queue<int> students;
    stack<int> sandwiches;
    int stuArr[] = {1, 1, 0, 0};
    int sandArr[] = {0, 1, 0, 1};
    int n = 4;

    for (int i = 0; i < n; i++) students.push(stuArr[i]);

    for (int i = n - 1; i >= 0; i--) sandwiches.push(sandArr[i]);

    cout << "Number of students unable to eat: " 
        << countStudents(students, sandwiches);
    return 0;
}
