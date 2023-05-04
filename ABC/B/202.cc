#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    rep(i, s.size()) {
        if (s[i] == '6')
            cout << '9';
        else if (s[i] == '9')
            cout << '6';
        else
            cout << s[i];
    }
    cout << endl;
    return 0;
}