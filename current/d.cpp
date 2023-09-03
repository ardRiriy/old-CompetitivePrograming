#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = 1e18;
const int N_INF = LLONG_MIN;
using namespace std;

void solve() {
    // hogehoge
    int n;
    cin >> n;
    vector<vector<int>> d(n, vector<int>(n, 0));
    rep(i, n){
        for(int j = i + 1; j < n; j++){
            cin >> d[i][j];
            d[j][i] = d[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -INF));

    dp[0][0] = 0;

    for(int i = 1; i < (1 << n); i++){
        rep(j, n){
            if (!(i >> j & 1)) continue; 
            rep(k, n){
                if(!(i >> k & 1) || k == j) continue;
                if (dp[i ^ (1 << j)][k] == -INF) continue;
                dp[i][j] = max(dp[i][j], dp[i ^ (1 << j)][k] + d[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(dp[(1 << n) - 1][i] < 0) continue;
        ans= max(ans, dp[(1 << n) - 1][i]);
    }
    print(ans);

}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    std::cin.tie(0)->sync_with_stdio(0);
    int times = 1;
    // cin >> times;
    while (times--) solve();
    return 0;
}
