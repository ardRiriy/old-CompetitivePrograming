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
void solve() {
    int N;
    cin >> N;
    int P[N];
    rep(i, N) cin >> P[i];

    int minimam_place = INF;
    int ans = 0;
    rep(i, N) {
        if (P[N - i - 1] <= N - i && P[N - i - 1] < minimam_place) {
            ans++;
            minimam_place = P[N - i - 1];
        }
    }
    cout << ans << endl;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int times = 0;
    cin >> times;
    while (times--) {
        solve();
    }
    return 0;
}
