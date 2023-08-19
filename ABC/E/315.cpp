#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
using namespace std;
bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int x, int n) { int result = 1; while(n > 0){ if((n & 1) == 1){ result *= x; } x *= x; n >>= 1; } return result; } /*x^nを計算*/
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

/// @brief トポロジカルソート
/// @param graph グラフ
/// @return トポロジカルソートの結果で辞書順最小のもの。グラフが閉路を含む場合は空の配列
/// @note 1.3 トポロジカルソートの結果で辞書順最小のものを得る
/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/topological-sort
std::vector<int> TopologicalSort(const std::vector<std::vector<int>>& graph)
{
	std::vector<int> indegrees(graph.size());

	for (const auto& v : graph)
	{
		for (const auto& to : v)
		{
			++indegrees[to];
		}
	}

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	for (int i = 0; i < (int)graph.size(); ++i)
	{
		if (indegrees[i] == 0)
		{
			pq.push(i);
		}
	}

	std::vector<int> result;

	while (!pq.empty())
	{
		const int from = pq.top(); pq.pop();

		result.push_back(from);

		for (const auto& to : graph[from])
		{
			if (--indegrees[to] == 0)
			{
				pq.push(to);
			}
		}
	}

	if (result.size() != graph.size())
	{
		return{};
	}

	return result;
}



map<int, bool> visited;
void dfs(const vector<vector<int>>& graph, int v) {
  visited[v] = true;

  for(int to : graph[v]) {
    if(!visited[to]) {
      dfs(graph, to);
    }
  }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    vector<vector<int>> v(n);
    rep(i, n){
        int c;
        cin >> c;
        rep(j, c){
            int p;
            cin >> p;
            p--;
            graph[p].push_back(i);
            v[i].push_back(p);
        }
    }

    const vector<int> rs = TopologicalSort(graph);

      // 1に到達可能かDFS
    dfs(v, 0);
    for(int i: rs){
        if(!visited[i] || i == 0) continue;
        cout << (i+1) << " ";
    }
    print("");
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
