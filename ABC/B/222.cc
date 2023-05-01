#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, p;
    cin >> n >> p;
    int ans = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if (a < p) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}