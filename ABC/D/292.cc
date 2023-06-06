/* とりあえず違いそうなことがわかった．
考えていた方針としては，ある頂点が含まれる連結グラフに対して，
頂点数=辺の数となるかを愚直に調べること． */

#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;

using namespace std;
bool chmin(int &a, int b) {
    if (a > b) {
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
    vector<vector<int>> graph(N);
    vector<int> degree(N, 0);
    vector<int> dist(N, -1);

    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    rep(i, N) {
        if (dist[i] != -1) continue;
        queue<int> que;
        dist[i] = 0;
        que.push(i);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int u : graph[v]) {
                if (dist[u] != -1) continue;
                dist[u] = dist[v] + 1;
            }
        }
    }
    return 0;
}
