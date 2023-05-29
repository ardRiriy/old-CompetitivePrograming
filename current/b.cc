#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(m, vector<int>(n));

    vector<vector<bool>> ans(n + 1, vector<bool>(n + 1));

    rep(i, m) rep(j, n) cin >> vec[i][j];

    rep(i, m) rep(j, n) {
        if (j == 0) continue;
        ans[vec[i][j]][vec[i][j - 1]] = true;
        ans[vec[i][j - 1]][vec[i][j]] = true;
    }

    int cnt = 0;
    rep(i, n) rep(j, n) {
        if (i == j) continue;
        if (!ans[i + 1][j + 1]) cnt++;

        /*         if (ans[i + 1][j + 1])
                    cout << 1 << endl;
                else
                    cout << 0 << endl; */
    }
    cnt /= 2;
    cout << cnt << endl;
    return 0;
}
