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

struct Edge {
    int to;
    int cost;
};

using Graph = vector<vector<Edge>>;

void Dijkstra(Graph &graph, vector<int> &dist, int start){
    auto compare = [](pair<int, int> & a, pair<int, int> & b) {
        return a.second > b.second;
    };
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        decltype(compare)
    > pq{compare}; // {行先, そこまでの最短距離候補}

    pq.push({start, 0});
    while (!pq.empty()){
        auto p = pq.top();
        pq.pop();
        if(dist[p.first] != INF) continue;
        dist[p.first] = p.second;
        rep(i, graph[p.first].size()){
            if(dist[graph[p.first][i].to] == INF){
                pq.push({graph[p.first][i].to, graph[p.first][i].cost + p.second});
            }
        }
    }
}

void solve() {
    // hogehoge
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    Graph g(n1 + n2);
    rep(i, m){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back({v, 1});
        g[v].push_back({u, 1});
    }

    vector<int> d1(n1 + n2, INF), d2(n1 + n2, INF);
    Dijkstra(g, d1, 0);
    Dijkstra(g, d2, n1 + n2 - 1);
    int n = -1, l = -1;
    rep(i, n1 + n2){
            if(d1[i] != INF) chmax(n, d1[i]);
            if(d2[i] != INF) chmax(l, d2[i]);
    }    
    print(n + l + 1);
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
