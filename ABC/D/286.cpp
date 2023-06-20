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

vector<int> coin(101, 0);

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int N, X;
    cin >> N >> X;
    vector<vector<bool>> dp(N + 1, vector<bool>(X + 1, false));
    dp[0][0] = true;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        rep(k, X + 1) {
            if (dp[i][k]) {
                rep(l, b + 1) {
                    if (k + a * l <= X) {
                        dp[i + 1][k + a * l] = true;
                    }
                }
            }
        }
    }
    if (dp[N][X]) YES else NO return 0;
}
