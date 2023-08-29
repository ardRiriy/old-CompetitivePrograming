#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
using namespace std;
class UnionFind { 
    private: map<int, int> uf;
    public:
    int root(int n) { if (uf.find(n) == uf.end()) uf[n] = -1; if (uf[n] < 0) return n; else return uf[n] = root(uf[n]); }
    bool connected(int a, int b) { return root(a) == root(b); }
    void marge(int a, int b) { int root_a = root(a); int root_b = root(b); if (root_a != root_b) { if (uf[root_a] > uf[root_b]) swap(root_a, root_b); uf[root_a] += uf[root_b]; uf[root_b] = root_a; }}
    int size(int n) { return -uf[root(n)]; }
};
bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int x, int n) { int result = 1; while(n > 0){ if((n & 1) == 1){ result *= x; } x *= x; n >>= 1; } return result; } /*x^nを計算*/
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

void solve() {
    // hogehoge
    int n, W;
    cin >> n >> W;
    // i番目の品物を，価値がjになるように持った時の重さdp[i][j]
    vector<vector<int>> dp(n+1, vector<int>(1e5 + 1, INF));
    rep(i, n+1) dp[i][0] = 0;

    rep(i, n){
        int w, v;
        cin >> w >> v;
        revrep(j, 1e5){
            if(dp[i][j] == INF) continue;
            dp[i+1][j] = dp[i][j];
            chmin(dp[i+1][j+v], dp[i][j] + w);

            //print(i+1<< " : " << j+v << " : " << dp[i][j] + w << " : " << dp[i+1][j+v]);
        }
    }
    int ans = -INF;
    rep(i, n+1)rep(j, 1e5+1) {
        if(dp[i][j] <= W) chmax(ans, j);
        //if(dp[i][j] != INF) print(j << " " << dp[i][j]);
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
