#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;

    char str[10][50];
    cout << "Enter " << n << " strings:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;
            while (str[i][k] != '\0' && str[j][k] != '\0' && str[i][k] == str[j][k]) {
                k++;
            }
            if (str[i][k] > str[j][k]) {
                char temp[50];
                int t = 0;
                while ((temp[t] = str[i][t]) != '\0') t++;
                t = 0;
                while ((str[i][t] = str[j][t]) != '\0') t++;
                t = 0;
                while ((str[j][t] = temp[t]) != '\0') t++;
            }
        }
    }

    cout << "\nStrings in alphabetical order:"<<endl;
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
