#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i % 2 == 0) {
            if (s[i] <= 'Z' && s[i] >= 'A') continue;
        } else {
            if (s[i] <= 'z' && s[i] >= 'a') continue;
        }
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}