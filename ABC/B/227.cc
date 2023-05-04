#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
#define rep2(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
    set<int> s;
    rep(a, 1000) rep(b, 1000) s.insert(4 * a * b + 3 * a + 3 * b);

    int n;
    cin >> n;
    int ans = 0;

    rep2(i, n) {
        int k;
        cin >> k;
        if (s.count(k) == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}