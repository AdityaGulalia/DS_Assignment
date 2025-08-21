#include <iostream>
using namespace std;

bool isSubstring(char s1[], int len1, char s2[], int len2) {
    if (len2 > len1) return false;

    for (int i = 0; i <= len1 - len2; i++) {
        int j = 0;
        while (j < len2 && s1[i + j] == s2[j]) j++;
        if (j == len2) return true;
    }
    return false;
}

int main() {
    char str[100];
    cout << "Enter string: ";
    cin >> str;

    int n = 0;
    while (str[n] != '\0') n++;

    bool possible = false;

    for (int i = 0; i < n - 2 && !possible; i++) {
        for (int j = i + 1; j < n - 1 && !possible; j++) {
            int lenA = i + 1;
            int lenB = j - i;
            int lenC = n - j - 1;

            char A[100], B[100], C[100];
            for (int k = 0; k < lenA; k++) A[k] = str[k];
            A[lenA] = '\0';

            for (int k = 0; k < lenB; k++) B[k] = str[i + 1 + k];
            B[lenB] = '\0';

            for (int k = 0; k < lenC; k++) C[k] = str[j + 1 + k];
            C[lenC] = '\0';

            // check conditions
            if (isSubstring(B, lenB, A, lenA) && isSubstring(C, lenC, A, lenA)) possible = true;
            if (isSubstring(A, lenA, B, lenB) && isSubstring(C, lenC, B, lenB)) possible = true;
            if (isSubstring(A, lenA, C, lenC) && isSubstring(B, lenB, C, lenC)) possible = true;
        }
    }

    if (possible) cout << "YES";
    else cout << "NO";

    return 0;
}
