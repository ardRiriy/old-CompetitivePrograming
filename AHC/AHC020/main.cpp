#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;

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

int distance(pair<int, int> &p1, pair<int, int> &p2) {
    return pow(abs(p1.first - p2.first), 2) +
           pow(abs(p1.second - p2.second), 2);
}
typedef pair<int, int> Pair;

vector<int> primMST(vector<vector<Pair>> &adj, int V) {
    priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
    int src = 0;  // Taking vertex 0 as source
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;  // Include vertex in MST

        for (auto &i : adj[u]) {
            int v = i.first;
            int weight = i.second;
            if (inMST[v] == false && key[v] > weight) {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    return parent;  // return parent as representation of MST
}
signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    srand(time(NULL));
    clock_t start = clock();
    int time_limit = 1900;

    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, int>> point(N);

    vector<vector<int>> degree(M, vector<int>(2));

    rep(i, N) {
        int x, y;
        cin >> x >> y;
        point[i] = make_pair(x, y);
    }
    vector<vector<pair<int, int>>> adj(N);
    rep(i, M) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        degree[i][0] = u;
        degree[i][1] = v;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> mst = primMST(adj, N);
    vector<pair<int, int>> resident(K);
    rep(i, K) {
        int x, y;
        cin >> x >> y;
        resident[i] = make_pair(x, y);
    }

    // 初期解の生成
    // まずはK人全員が視聴可能となるように，onにしていく

    // 一番近い電波塔を保存
    // 0: 最寄りの電波塔(0-index)
    // 1: 最寄りの電波塔までの距離(を2乗したもの)
    // 2: 住人番号
    vector<vector<int>> nearest_tower(K, vector<int>(3));
    vector<int> ans_p(N, 0);
    rep(i, K) {
        int nnn = INF;
        int now_dist = INF;
        rep(j, N) if (chmin(now_dist, distance(point[j], resident[i]))) nnn = j;
        nearest_tower[i][0] = nnn;
        nearest_tower[i][1] = now_dist;
        nearest_tower[i][2] = i;
    }

    bool ck[K] = {false};
    std::sort(nearest_tower.begin(), nearest_tower.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                  return a[1] > b[1];
              });

    // rep(i, K) { cout << nearest_tower[i][1] << endl; }
    rep(i, K) {
        if (ck[i]) continue;
        ck[i] = true;
        chmax(ans_p[nearest_tower[i][0]], sqrt(nearest_tower[i][1]) + 1);
        for (int k = i; k < K; k++) {
            if (!ck[k]) continue;
            if (distance(point[nearest_tower[i][0]],
                         resident[nearest_tower[k][2]]) <=
                nearest_tower[i][1]) {
                ck[k] = true;
            }
        }
    }
    vector<int> ans_b(M, 0);
    rep(i, M) {
        if (mst[degree[i][0]] == degree[i][1] ||
            mst[degree[i][1]] == degree[i][0]) {
            ans_b[i] = 1;
        }
    }

    for (int i : ans_p) std::cout << i << " ";
    std::cout << endl;
    for (int i : ans_b) std::cout << i << " ";
    std::cout << endl;
    return 0;
}
