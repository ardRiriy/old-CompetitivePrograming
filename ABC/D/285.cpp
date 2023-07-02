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

void solve() {
    // hogehoge
    int N;
    map<string, int> mp;
    int cnt = 1;
    cin >> N;
    vector<pair<int, int>> vec(N);
    UnionFind uf(2*N+2);
    rep(i, N){
        string s1, s2;
        cin >> s1 >> s2;
        if(mp[s1] == 0){
            mp[s1] = cnt;
            cnt++;
        }
        if(mp[s2] == 0){
            mp[s2] = cnt;
            cnt++;
        }
        uf.marge(mp[s1], mp[s2]);
        vec[i] = {mp[s1], mp[s2]};
    }

    map<int, int> degree;
    rep(i, N){
        degree[uf.root(vec[i].first)]++;
    }

    rep(i, N){
        if(degree[i] == 0)continue;
        if(degree[i] == uf.size(i)){
            print("No");
            return;
        }
    }
    print("Yes");
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
