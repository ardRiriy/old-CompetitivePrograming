#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
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
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<set<int>> vec(n);
    int ans = n;

    while(q--){
        int que;
        cin >> que;
        if(que == 1){
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(vec[u].empty()) ans--;
            if(vec[v].empty()) ans--;
            vec[u].insert(v);
            vec[v].insert(u);

        }else{
            int u;
            cin >> u;
            u--;
            itrep(itr, vec[u]){
                vec[*itr].erase(u);
                if(vec[*itr].empty())ans++;
            }
            if(!vec[u].empty()){
                vec[u].clear();
                ans++;
            }
        }
        print(ans);
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
