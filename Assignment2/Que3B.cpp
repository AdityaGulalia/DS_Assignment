#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int left = 0, right = n - 2; 

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == mid + 1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + 1;  
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[50];
    cout << "Enter " << n - 1 << " sorted numbers:\n";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    cout << "Missing number is: " << findMissing(arr, n);
    return 0;
}