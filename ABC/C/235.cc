#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, q;
    cin >> n >> q;

    map<int, vector<int>> vvv;

    rep(i, n) {
        int k;
        cin >> k;
        vvv[k].push_back(i + 1);
    }

    rep(i, q) {
        int x, k;
        cin >> x >> k;
        if (vvv[x].size() < k) {
            cout << -1 << endl;
            continue;
        }
        cout << vvv[x][k - 1] << endl;
    }

    return 0;
}