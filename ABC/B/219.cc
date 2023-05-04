#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    string s[3];
    rep(i, 3) cin >> s[i];
    string k;
    cin >> k;

    rep(i, k.size()) cout << s[k[i] - '1'];
    cout << endl;
    return 0;
}