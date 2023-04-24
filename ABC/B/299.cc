#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, t;

    cin >> n >> t;

    vector<int> c(n);
    vector<int> r(n);

    rep(i, n) cin >> c[i];

    int one_c = c[0];

    rep(i, n) cin >> r[i];

    int max = -1, max_i = 0;
    int mmx = -1, mmx_i = 0;
    bool cat = false;

    rep(i, n) {
        if (c[i] == t) {
            cat = true;
            if (max < r[i]) {
                max_i = i;
                max = r[i];
            }
        } else if (c[i] == one_c && mmx < r[i]) {
            mmx_i = i;
            mmx = r[i];
        }
    }

    if (cat)
        cout << max_i + 1 << endl;
    else
        cout << mmx_i + 1 << endl;

    return 0;
}