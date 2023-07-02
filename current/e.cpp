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

int mex(int a, int b, int c){
    rep(i, 3){
        if(a != i && b != i && c!= i)return i;
    }
    return 3;
}

void solve() {
    // hogehoge
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    string S;
    cin >> S;

    vector<vector<int>> M(3), E(3), X(3);

    rep(i, N){
        if(S[i] == 'M'){
            M[A[i]].push_back(i);
        }
        else if(S[i] == 'E'){
            E[A[i]].push_back(i);
        }
        else if(S[i] == 'X'){
            X[A[i]].push_back(i);
        }
    }

    int ans = 0;

    rep(i, 3){
        rep(k, 3){
            rep(l, 3){
                if(i != 0 && k != 0 && l != 0) continue;
                for(int q: M[i]){
                    int idx_e = b_search(E[k], q);
                    if(idx_e == E[k].size()) continue;

                    for(int kk = idx_e; kk < E[k].size(); kk++){
                        int idx_x = b_search(X[l], E[k][kk]);
                        if(idx_x == X[l].size())continue;

                        ans += (X[l].size() - idx_x ) * mex(i, k, l);
                        // print(idx_x << X[l].size() << " " << mex(i, k, l) << i << k << l);
                    }
                }
            }
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
