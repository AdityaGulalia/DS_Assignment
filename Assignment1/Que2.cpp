#include <iostream>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    int temp[n]; 
    int newSize = 0;

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            temp[newSize] = arr[i];
            newSize++;
        }
    }
    for (int i = 0; i < newSize; i++) {
        arr[i] = temp[i];
    }
    n = newSize;
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    displayArray(arr, n);

    removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    displayArray(arr, n);

    return 0;
}