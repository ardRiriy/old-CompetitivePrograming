#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    string s, t;
    cin >> s >> t;
    int cnt = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != t[i]) {
            char tmp;
            tmp = s[i];
            s[i] = s[i + 1];
            s[i + 1] = tmp;
            cnt++;
        }
    }
    if (cnt > 1 || s != t)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}