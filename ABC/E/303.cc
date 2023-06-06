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

    int N;  // 頂点の数

    cin >> N;
    vector<vector<int>> graph(N);
    vector<int> degree(N, 0);  // 頂点の次数
    vector<int> dist(N, -1);   // 選択した葉からの距離

    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        degree[u]++;
        degree[v]++;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int leaf;
    rep(i, N) if (degree[i] == 1) {
        leaf = i;
        break;
    }

    // BFS
    queue<int> que;
    dist[leaf] = 0;
    que.push(leaf);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int u : graph[v]) {
            if (dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            que.push(u);
        }
    }

    // 答え
    vector<int> ans;
    rep(i, N) {
        if (dist[i] % 3 == 1) {
            ans.push_back(degree[i]);
        }
    }
    sort(ans.begin(), ans.end());

    for (int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}
