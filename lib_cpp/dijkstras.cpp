#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
#define all(a) a.begin(), a.end()
const int INF = LLONG_MAX;
using namespace std;


///////////////////////////////////////////////////////////////////

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


///////////////////////////////////////////////////////////////////

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    std::cin.tie(0)->sync_with_stdio(0);

    return 0;
}

/*
5 5
1 2 4
1 3 2
2 3 1
2 4 7
3 4 5
*/
