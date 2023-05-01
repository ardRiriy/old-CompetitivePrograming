
#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    rep(i, n) {
        rep(j, k) { ans += 100 * (i + 1) + (j + 1); }
    }

    cout << ans << endl;
    return 0;
}