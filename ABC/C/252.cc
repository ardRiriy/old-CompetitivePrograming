#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;

    int v[n][10];

    rep(i, n) {
        string s;
        cin >> s;
        rep(j, 10) v[i][j] = s[j] - '0';
    }

    int ans = 10000;
    rep(i, 10) {
        int t = -1;
        bool check[n];
        rep(j, n) check[j] = false;
        int cnt = 0;
        while (true) {
            t++;
            rep(j, n) {
                if (!check[j] && v[j][t % 10] == i) {
                    check[j] = true;
                    cnt++;
                    break;
                }
            }
            if (cnt == n) break;
        }
        if (ans > t) ans = t;
    }

    cout << ans << endl;
    return 0;
}