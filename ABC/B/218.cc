#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    rep(i, 26) {
        int a;
        cin >> a;
        cout << char('a' + (a - 1));
    }
    cout << endl;
    return 0;
}