#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1; 
        }
    }
    return n; 
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[50];
    cout << "Enter " << n - 1 << " numbers:\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number is: " << findMissing(arr, n);
    return 0;
}
