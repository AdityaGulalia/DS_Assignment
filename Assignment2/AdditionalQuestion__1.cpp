#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    
    int arr[50];
    cout << "Enter " << n << " elements:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(arr[i] - arr[j]) == k) {
                count++;
                cout << "(" << arr[i] << ", " << arr[j] << ")"<<endl;
            }
        }
    }

    cout << "Total pairs with difference " << k << " = " << count;
    return 0;
}
