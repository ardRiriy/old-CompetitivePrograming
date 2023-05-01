#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    s += s;  // 左端の文字を右端に移動させる操作を単純化している．
    int ans = 1ll << 60;

    rep(i, n) {
        int tmp = a * i;
        rep(j, n / 2) {
            int l = i + j;
            int r = i + n - 1 - j;
            if (s[l] != s[r]) tmp += b;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;
    return 0;
}