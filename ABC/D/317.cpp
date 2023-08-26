#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
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

int target;
int n;

void solve() {
    // hogehoge
    cin >> n;
    int sum = 0;
    int now = 0;
    vector<int> x(n), y(n);
    vector<int> z(n);
    rep(i, n){
        cin >> x[i] >> y[i] >> z[i];
        sum += z[i];
        if(x[i] > y[i]) now += z[i];
    }
    sum = (sum + 1) / 2;
    if(sum <= now){
        print(0);
        return;
    }
    //print(now << " " << sum);
    vector<int> dp(sum + 1, INF);
    dp[now] = 0;
    rep(i, n){
        if(x[i] > y[i]) continue;
        int get = z[i];
        int cost = (y[i] - x[i]) / 2 + 1;
        for(int j = sum; j >= 0; j--){
            if(dp[j] == INF) continue;
            int next = min(sum, j + get);
            dp[next] = min(dp[next], dp[j] + cost);
        }
    }
    print(dp[sum]);
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
