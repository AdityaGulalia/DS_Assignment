#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int freq[256] = {0};
    string q = "";

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        freq[c]++;
        q += c;
        while (!q.empty() && freq[q[0]] > 1) {
            q.erase(q.begin());
        }

        if (q.empty()) cout << -1 << " ";
        else cout << q[0] << " ";
    }
    return 0;
}

