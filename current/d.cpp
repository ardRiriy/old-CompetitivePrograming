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

int H, W;
vector<string> vec;
char ck[5] = {'s', 'n', 'u', 'k', 'e'};

vector<vector<bool>> ed(501, vector<bool>(501, false));

bool dfs(int cnt, int x, int y){
    if(ed[x][y]) return false; 
    ed[x][y] = true; 
    bool ans = false;
    if(x == H-1 && y == W-1)return true;
    if(x != 0) if(vec[x-1][y] == ck[(cnt+1) % 5]) ans = (ans || dfs(cnt+1, x-1, y));
    if(y != 0) if(vec[x][y-1] == ck[(cnt+1) % 5]) ans = (ans || dfs(cnt+1, x, y-1));
    if(x != H-1) if(vec[x+1][y] == ck[(cnt+1) % 5]) ans = (ans || dfs(cnt+1, x+1, y));
    if(y != W-1) if(vec[x][y+1] == ck[(cnt+1) % 5]) ans = (ans || dfs(cnt+1, x, y+1));
    return ans;
}

void solve() {
    // hogehoge
    cin >> H >> W;
    vec.resize(H);
    rep(i, H)cin >> vec[i];
    bool ans = false;

    if(vec[0][0] == ck[0]){
        bool ck1 = false, ck2 = false;
        if(vec[1][0] == ck[1]) ck1 = dfs(1, 1, 0);
        if(vec[0][1] == ck[1]) ck2 = dfs(1, 0, 1);
        ans = ck1 || ck2;
    }

    if(ans)print("Yes");
    else print("No");

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
