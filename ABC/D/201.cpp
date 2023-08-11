#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
using namespace std;
class UnionFind { 
    private: vector<int> uf;
    public:
    UnionFind(int size) : uf(size) { for (int i = 0; i < size; i++) uf[i] = -1; }
    int root(int n) { if (uf[n] < 0) return n; else return uf[n] = root(uf[n]); }
    bool connected(int a, int b) { return root(a) == root(b); }
    void marge(int a, int b) { int root_a = root(a); int root_b = root(b); if (root_a != root_b) { if (uf[root_a] > uf[root_b]) swap(root_a, root_b); uf[root_a] += uf[root_b]; uf[root_b] = root_a; }}
    int size(int n) { return -uf[root(n)]; }
};
bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int base, int exponent) {int result = 1;for (int i = 0; i < exponent; i++) result *= base; return result; }
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

void solve() {
    // hogehoge
    int h, w;
    cin >> h >> w;
    vector<string> bd(h);
    rep(i, h) cin >> bd[i];

    vector<vector<int>> dp(h, vector<int>(w, N_INF));
    dp[h-1][w-1] = 0;
        
    revrep(i, h-1){
        revrep(j, w-1){
            if(i+1 < h){
                chmax(dp[i][j], -dp[i+1][j] + (bd[i+1][j] == '+' ? 1 : -1));
            }
            if(j+1 < w){
                chmax(dp[i][j], -dp[i][j+1] + (bd[i][j+1] == '+' ? 1 : -1));
            }
        }
    }
    if(dp[0][0] > 0) print("Takahashi");
    else if(dp[0][0] < 0) print("Aoki");
    else print("Draw");
    rep(i, h){
        rep(j, w) {
            cout << dp[i][j] << " ";
        }
        print("")
    }
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
