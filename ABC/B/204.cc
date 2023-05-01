#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;

    int ans = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a > 10) {
            ans += a - 10;
        }
    }
    cout << ans << endl;
    return 0;
}