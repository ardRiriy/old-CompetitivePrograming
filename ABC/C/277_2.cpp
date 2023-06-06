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
    UnionFind(int n) : uf(n) {
        for (int i = 0; i < n; i++) uf[i] = -1;
    }

    int root(int n) {
        if (uf[n] >= 0) uf[n] = root(uf[n]);
        return n;
    }

    bool connected(int a, int b) { return root(a) == root(b); }

    void marge(int a, int b) {
        int root_a = root(a);
        int root_b = root(b);
        if (root_a != root_b) {
            if (root_a > root_b) swap(root_a, root_b);
            uf[root_a] += root_b;
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

    int N;
    cin >> N;

    UnionFind uf(1000000000);
    vector<int> l;
    rep(i, N) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        l.push_back(u);
        l.push_back(v);
        uf.marge(u, v);
    }

    int ans = 0;
    for (int i : l)
        if (uf.connected(0, i)) chmax(ans, i + 1);
    cout << ans << endl;
    return 0;
}
