#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    string a[h];
    string b[h];

    rep(i, h) cin >> a[i];
    rep(i, h) cin >> b[i];

    rep(s, h) {
        rep(t, w) {
            bool ck = true;
            rep(i, h) {
                rep(j, w) {
                    if (a[(i + s) % h][(j + t) % w] != b[i][j]) {
                        ck = false;
                    }
                }
            }
            if (ck) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}