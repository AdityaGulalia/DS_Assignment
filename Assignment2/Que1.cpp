#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num)
            return i; 
    }
}

int binarySearch(int arr[], int n, int num) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == num)
            return mid; 

        if (arr[mid] < num)
            left = mid + 1; 
        else
            right = mid - 1;
    }
    return -1; 
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[50];
    cout << "Enter elements (sorted for binary search):"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    // Linear Search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1)
        cout << "Linear Search: Element found at index " << linearResult << endl;
    else
        cout << "Linear Search: Element not found"<<endl;

    // Binary Search
    int binaryResult = binarySearch(arr, n, key);
    if (binaryResult != -1)
        cout << "Binary Search: Element found at index " << binaryResult << endl;
    else
        cout << "Binary Search: Element not found"<<endl;

    return 0;
}
