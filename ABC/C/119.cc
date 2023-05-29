#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;

using namespace std;
bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int n, A, B, C;
vector<int> l;

int dfs(int pos, int a, int b, int c) {
    if (pos == n) {
        if (a == 0 || b == 0 || c == 0)
            return INF;
        else
            return abs(a - A) + abs(b - B) + abs(c - C);
    }

    int res = dfs(pos + 1, a, b, c);  // 配列のpos番目の竹は採用しない
    chmin(res, dfs(pos + 1, a + l[pos], b, c) + (a ? 10 : 0));  // aの竹
    chmin(res, dfs(pos + 1, a, b + l[pos], c) + (b ? 10 : 0));  // bの竹
    chmin(res, dfs(pos + 1, a, b, c + l[pos]) + (c ? 10 : 0));  // cの竹

    return res;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    cin >> n >> A >> B >> C;
    l.resize(n);
    rep(i, n) cin >> l[i];

    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}
