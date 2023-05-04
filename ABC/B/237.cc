#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h) rep(j, w) cin >> a[i][j];
    rep(i, w) {
        { rep(j, h) cout << a[j][i] << " "; }
        cout << endl;
    }
    return 0;
}