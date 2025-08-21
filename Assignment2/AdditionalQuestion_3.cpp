#include <iostream>
using namespace std;

bool areAnagrams(char str1[], char str2[]) {
    int count1[26] = {0}, count2[26] = {0};

    int i = 0;
    while (str1[i] != '\0') {
        count1[str1[i] - 'a']++;
        i++;
    }

    int j = 0;
    while (str2[j] != '\0') {
        count2[str2[j] - 'a']++;
        j++;
    }

    if (i != j) return false;  
    for (int k = 0; k < 26; k++) {
        if (count1[k] != count2[k]) return false;
    }
    return true;
}

int main() {
    char str1[50], str2[30];   
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    if (areAnagrams(str1, str2))
        cout << "YES, they are Anagrams";
    else
        cout << "NO, they are not Anagrams";

    return 0;
}
