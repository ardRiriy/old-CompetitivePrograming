#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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

int mex(int bit) {
    if ((bit & 1) == 0) return 0;
    if ((bit & (1 << 1)) == 0) return 1;
    if ((bit & (1 << 2)) == 0) return 2;
    return 3;
}

void solve() {
    // hogehoge
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    string s;
    cin >> s;

    vector<vector<int>> dp(3, vector<int>(8, 0));
    rep(i, N){
        int a1 = a[i];
        char s1 = s[i];
        if(s1 == 'M'){
            dp[0][1 << a1] += 1;
        }else if(s1 == 'E'){
            for(int bit = 0; bit < 8; bit++){
                int nbit = bit | (1 << a1);
                dp[1][nbit] += dp[0][bit];
            }
        }else{
            for(int bit = 0; bit < 8; bit++){
                int nbit = bit | (1 << a1);
                dp[2][nbit] += dp[1][bit];
            }
        }
    }

    int ans = 0;
    for(int bit = 0; bit < 8; bit++){
        ans += mex(bit) * dp[2][bit];
    }

    cout << ans << endl;
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
