#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    string s;

    cin >> n;
    cin >> s;
    bool sta = false;

    rep(i, n) {
        if (s[i] == '.')
            continue;
        else if (s[i] == '|')
            sta = !sta;
        else if (s[i] == '*' && sta) {
            cout << "in" << endl;
            return 0;
        } else {
            cout << "out" << endl;
            return 0;
        }
    }

    return 0;
}