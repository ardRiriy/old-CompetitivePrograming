#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
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

void solve() {
    // hogehoge
    int H, W;
    cin >> H >> W;
    UnionFind uf(H*W);
    vector<vector<bool>> vec(H, vector<bool>(W, false));
    int Q;
    cin >> Q;
    while(Q--){
        int q;
        cin >> q;
        if(q == 1){
            int r, c;
            cin >> r >> c; 
            r--;c--;

            vec[r][c] = true;
            if(r-1 >= 0 && vec[r-1][c]) uf.marge(r*W+c, (r-1)*W+c);
            if(c-1 >= 0 && vec[r][c-1]) uf.marge(r*W+c, r*W+c-1); 
            if(r+1 < H && vec[r+1][c]) uf.marge(r*W+c, (r+1)*W+c);
            if(c+1 < W && vec[r][c+1]) uf.marge(r*W+c, r*W+c+1); 
        }else{
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;c1--;r2--;c2--;
            if(r1 == r2 && c1 == c2) {if(vec[r1][c1]) YES else NO continue;}
            if(uf.connected(r1*W + c1, r2*W+c2)) YES else NO
        }
    }
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int times = 1;
    // cin >> times;
    while (times--) solve();
    return 0;
}
