#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    int temp[100];  
    int j = 0;     

    for (int i = 0; i < n && j < n; i++) {
        if (arr[i] == 2) {
            temp[j++] = 2;
            if (j < n) temp[j++] = 2; 
        } else {
            temp[j++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[50];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    duplicateTwos(arr, n);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
