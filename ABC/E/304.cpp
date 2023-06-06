#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;

class UnionFind {
   private:
    vector<int> uf;

   public:
    UnionFind(int size) : uf(size) {
        for (int i = 0; i < size; i++) uf[i] = -1;
    }

    int root(int n) {
        if (uf[n] < 0)
            return n;
        else
            return uf[n] = root(uf[n]);
    }

    bool connected(int a, int b) { return root(a) == root(b); }

    void marge(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);
        if (root_a != root_b) {
            if (uf[root_a] > uf[root_b]) swap(root_a, root_b);
            uf[root_a] += uf[root_b];
            uf[root_b] = root_a;
        }
    }

    int size(int n) { return -uf[root(n)]; }
};

bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

bool chmax(int &a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int N, M;
    cin >> N >> M;
    UnionFind uf(N + 1);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        uf.marge(u, v);
    }

    set<pair<int, int>> ng;
    int K;
    cin >> K;
    rep(i, K) {
        int x, y;
        cin >> x >> y;
        int u = uf.root(x);
        int v = uf.root(y);
        // u <= vを保証する
        if (v < u) swap(u, v);
        ng.insert(make_pair(u, v));
    }

    int Q;
    cin >> Q;
    rep(i, Q) {
        int p, q;
        cin >> p >> q;
        int u = uf.root(p);
        int v = uf.root(q);
        if (v < u) swap(u, v);
        if (ng.count(make_pair(u, v)) == 0) YES else NO;
    }
    return 0;
}
