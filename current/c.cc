#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;
bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

bool chmax(int &a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int H, W;
    cin >> H >> W;
    char a[H][W];
    rep(i, H) rep(k, W) cin >> a[i][k];

    int x1 = INF, x2 = N_INF, y1 = INF, y2 = N_INF;
    rep(i, H) {
        rep(k, W) {
            if (a[i][k] == '#') {
                chmin(x1, i);
                chmax(x2, i);
                chmin(y1, k);
                chmax(y2, k);
            }
        }
    }

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (a[i][j] == '.') {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
