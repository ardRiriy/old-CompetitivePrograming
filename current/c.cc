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
    int Ha, Wa;
    cin >> Ha >> Wa;
    vector<string> A(Ha);
    rep(i, Ha)cin >> A[i];

    int Hb, Wb;
    cin >> Hb >> Wb;
    vector<string> B(Hb);
    rep(i, Hb)cin >> B[i];

    int Hx, Wx;
    cin >> Hx >> Wx;
    vector<string> X(Hx);
    rep(i, Hx)cin >> X[i];

    vector<pair<int, int>> stA, stB, stX;
    rep(i, Ha) rep(k, Wa) if (A[i][k] == '#') stA.push_back({i, k});
    rep(i, Hb) rep(k, Wb) if (B[i][k] == '#') stB.push_back({i, k});
    rep(i, Hx) rep(k, Wx) if (X[i][k] == '#') stX.push_back({i, k});

    for (auto [ax, ay]: stA) {
        for (auto [bx, by]: stB) {
            vector<pair<int, int>> tmp(stX);
            for (auto [x, y]: stA) {
                auto it = find(tmp.begin(), tmp.end(), make_pair(ax - x, ay - y));
                if (it != tmp.end()) tmp.erase(it);
            }
            for (auto [x, y]: stB) {
                auto it = find(tmp.begin(), tmp.end(), make_pair(bx - x, by - y));
                if (it != tmp.end()) tmp.erase(it);
            }
            if (tmp.empty()) {
                print("Yes");
                return;
            }
        }
    }
    // If no valid overlay was found, print "No"
    print("No");
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
