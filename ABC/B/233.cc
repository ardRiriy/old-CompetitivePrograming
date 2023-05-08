#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int l, r;
    string s;
    cin >> l >> r >> s;
    reverse(s.begin() + l - 1, s.begin() + r);
    cout << s << endl;
    return 0;
}
