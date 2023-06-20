#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;
bool chmin(int& a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

bool chmax(int& a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int N;
    cin >> N;
    vector<pair<int, int>> vec(N);

    rep(i, N) {
        int a, b;
        cin >> a >> b;
        vec[i] = make_pair(a, b);
    }

    vector<vector<int>> dp(N + 1, vector<int>(2, N_INF));
    dp[0][0] = 0;

    rep(i, N) {
        rep(k, 2) {
            if (dp[i][k] == N_INF) continue;
            if (vec[i].first == 0) {
                // tabenai
                chmax(dp[i + 1][k], dp[i][k]);
                // taberu
                chmax(dp[i + 1][0], dp[i][k] + vec[i].second);
            } else {
                chmax(dp[i + 1][k], dp[i][k]);
                if (k == 0) {
                    chmax(dp[i + 1][1], dp[i][k] + vec[i].second);
                }
            }
        }
        // cout << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
    }
    cout << max(dp[N][0], dp[N][1]) << endl;
    return 0;
}
