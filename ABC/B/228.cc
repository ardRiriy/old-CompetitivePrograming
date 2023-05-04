#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, x;
    cin >> n >> x;
    int a[n];
    rep(i, n) cin >> a[i];

    bool ch[n] = {false};
    int ans = 0;
    while (true) {
        // cout << "x: " << x << endl;
        if (ch[x - 1])
            break;
        else {
            ch[x - 1] = true;
            x = a[x - 1];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
