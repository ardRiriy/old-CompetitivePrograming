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
    private: map<int, int> uf;
    public:
    int root(int n) { if (uf.find(n) == uf.end()) uf[n] = -1; if (uf[n] < 0) return n; else return uf[n] = root(uf[n]); }
    bool connected(int a, int b) { return root(a) == root(b); }
    void marge(int a, int b) { int root_a = root(a); int root_b = root(b); if (root_a != root_b) { if (uf[root_a] > uf[root_b]) swap(root_a, root_b); uf[root_a] += uf[root_b]; uf[root_b] = root_a; }}
    int size(int n) { return -uf[root(n)]; }
};
bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int base, int exponent) {int result = 1;for (int i = 0; i < exponent; i++) result *= base; return result; }
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

vector<vector<int>> dp;
vector<vector<bool>> ck;
int a, b;

void solve() {
    // hogehoge
    int k;
    cin >> a >> b >> k;
    dp.resize(a+1, vector<int>(b+1, 0));
    ck.resize(a+1, vector<bool>(b+1, false));
    rep(i, a+1) dp[i][0] = 1; 
    rep(i, b+1) dp[0][i] = 1;    
    rep(i, a){
        rep(j, b){
            dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j];
        }
    }


/*     rep(i, a+1){
        rep(j, b+1){
            cout << dp[i][j] << " ";
        }
        print(" ");
    } */

    int i = a, j = b;
    string ans;
    while(true){
        if(i == 0){
            rep(k, j) ans.push_back('b');
            break;
        }else if(j == 0){
            rep(k, i) ans.push_back('a');
            break;
        }
        // print(k << " " <<dp[i][j]);
        if(k <= dp[i-1][j]){
            ans.push_back('a');
            i--;
        }else{
            ans.push_back('b');
            k -= dp[i-1][j];
            j--;
        }
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
