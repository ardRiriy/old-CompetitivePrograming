#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int x, y, z;
    cin >> x >> y >> z;

    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, LLONG_MAX));

    dp[0][0] = 0;
    rep(i, n) {
        rep(j, 2) {
            if (dp[i][j] == LLONG_MAX) continue;

            if (s[i] == 'a') {
                if (j == 0) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + x);
                    dp[i + 1][1 - j] = min(dp[i + 1][1 - j], dp[i][j] + y + z);
                } else {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + y);
                    dp[i + 1][1 - j] = min(dp[i + 1][1 - j], dp[i][j] + x + z);
                }
            }

            if (s[i] == 'A') {
                if (j == 1) {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + x);
                    dp[i + 1][1 - j] = min(dp[i + 1][1 - j], dp[i][j] + y + z);
                } else {
                    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + y);
                    dp[i + 1][1 - j] = min(dp[i + 1][1 - j], dp[i][j] + x + z);
                }
            }
        }
    }
    int ans = min(dp[n][0], dp[n][1]);

    cout << ans << endl;

    return 0;
}
