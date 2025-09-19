#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    int count0 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    int index = 0;
    while (count0--) arr[index++] = 0;
    while (count1--) arr[index++] = 1;
    while (count2--) arr[index++] = 2;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[50];
    cout << "Enter elements (0,1,2 only): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort012(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

