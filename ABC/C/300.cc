#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define CK                                              \
    a[i + s][j + s] == '#' && a[i + s][j - s] == '#' && \
        a[i - s][j - s] == '#' && a[i - s][j + s] == '#'

using namespace std;

signed main() {
    int h, w;
    cin >> h >> w;
    string a[h];

    int ans[105] = {0};
    rep(i, h) cin >> a[i];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int s = 1;
            if (a[i][j] == '.') continue;

            while (true) {
                if (i + s >= h || i - s < 0 || j + s >= w || j - s < 0) break;
                if (CK) {
                    s++;
                } else {
                    break;
                }
            }
            ans[s - 1]++;
        }
    }

    rep(i, min(h, w)) { cout << ans[i + 1] << " "; }
    cout << endl;
    return 0;
}