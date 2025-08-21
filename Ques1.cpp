#include <iostream>
using namespace std;

int arr[50];   
int n = 50;    

void create() {
    cout << "Enter " << 50 << " elements:\n";
    for (int i = 0; i < 50; i++) {
        cin >> arr[i];
    }
    cout << "Array created with 50 elements.\n";
}

void display() {
    cout << "Array elements: ";
    for (int i = 0; i < 50; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert() {
    int pos, val;
    cout << "Enter position (1 to " << 50 << "): ";
    cin >> pos;
    if (pos < 1 || pos > 50) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter value: ";
    cin >> val;
    arr[pos-1] = val;
    cout << "Element inserted at position " << pos << endl;
}

void remove() {
    int pos;
    cout << "Enter position (1 to " << 50 << "): ";
    cin >> pos;
    if (pos < 1 || pos > 50) {
        cout << "Invalid position!\n";
        return;
    }
    arr[pos-1] = 0;
    cout << "Element deleted at position " << pos << endl;
}

void linearSearch() {
    int key, found = -1;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < 50; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }
    if (found != -1)
        cout << "Element found at position " << found+1 << endl;
    else
        cout << "Element not found.\n";
}

int main() {
    int choice;
    while (true) {

        cout << "1. CREATE "<<endl;
        cout << "2. DISPLAY\n"<<endl;
        cout << "3. INSERT"<<endl;
        cout << "4. DELETE"<<endl;
        cout << "5. LINEAR SEARCH"<<endl;
        cout << "6. EXIT"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        if (choice == 1) {
            create();
        } 
        else if (choice == 2) {
            display();
        } 
        else if (choice == 3) {
            insert();
        } 
        else if (choice == 4) {
            remove();
        } 
        else if (choice == 5) {
            linearSearch();
        } 
        else {
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}