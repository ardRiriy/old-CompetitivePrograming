#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
#define all(a) a.begin(), a.end()
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

void solve() {
    // hogehoge
    int n, m;
    cin >> n >> m;
    map<int, vector<pair<int, int>>> mp;

    vector<pair<int, int>> pos(2 * m);

    for(int i = 0; i < 2 * m; i += 2){
        int a, b;
        cin >> a >> b >> pos[i].first >> pos[i].second;
        pos[i+1] = {-pos[i].first, -pos[i].second};
        a--;
        b--;
        mp[a].push_back({b, i});
        mp[b].push_back({a, i+1});
    }

    vector<pair<int, int>> ans(n);
    vector<bool> ck(n, false);
    ans[0] = {0, 0};
    ck[0] = true;
    queue<int> que;
    que.push(0);
    while (!que.empty()){
        auto p = que.front();
        que.pop();
        rep(i, mp[p].size()){
            if(ck[mp[p][i].first]) continue;
            ck[mp[p][i].first] = true;
            ans[mp[p][i].first] = {ans[p].first + pos[mp[p][i].second].first, ans[p].second + pos[mp[p][i].second].second};
            que.push(mp[p][i].first);
        }
    }

    rep(i, n){
        if(!ck[i]) print("undecidable");
        else print(ans[i].first << " " << ans[i].second);
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
