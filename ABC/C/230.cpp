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


void solve() {
    // hogehoge
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--; n--;
    int p, q, r, s;
    cin >> p >> q >> r >> s;
    p--, q--, r--, s--;

    set<pair<int, int>> st;

    // 1
    {
        int k = p - a;
        int ny = a + k;
        int nx = b + k;
        if(nx < r){
            int j = r - nx;
            nx += j;
            ny += j;
            k  += j;
        }
        while(nx <= s && ny <= q){
            st.insert({ny, nx});
            //print(ny << " " << nx);
            nx++;
            ny++;
        }
    }

    // 2
    {
        int k = p - a;
        int ny = p;
        int nx = b - k;
        if(nx > s){
            int j = nx - s;
            nx -= j;
            ny += j;
        }
        while(nx >= r && ny <= q){
            st.insert({ny, nx});
            //print(ny << " " << nx);
            nx--;
            ny++;
        }
    }

    rep(i, q-p+1){
        rep(j, s - r + 1){
            if(st.count({p + i, r + j})) cout << '#';
            else cout << '.';
        }
        print("");
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
