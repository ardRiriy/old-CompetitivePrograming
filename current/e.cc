#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;

class UnionFind {
   public:
    UnionFind() = default;

    /// @brief Union-Find 木を構築します。
    /// @param n 要素数
    explicit UnionFind(size_t n) : m_parentsOrSize(n, -1) {}

    /// @brief 頂点 i の root のインデックスを返します
    /// @param i 調べる頂点のインデックス
    /// @return 頂点 i の root のインデックス
    int find(int i) {
        if (m_parentsOrSize[i] < 0) {
            return i;
        }

        // 経路圧縮
        return (m_parentsOrSize[i] = find(m_parentsOrSize[i]));
    }

    /// @brief a のグループと b のグループを統合します。
    /// @param a 一方のインデックス
    /// @param b 他方のインデックス
    void merge(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            // union by size (小さいほうが子になる）
            if (-m_parentsOrSize[a] < -m_parentsOrSize[b]) {
                std::swap(a, b);
            }

            m_parentsOrSize[a] += m_parentsOrSize[b];
            m_parentsOrSize[b] = a;
        }
    }

    /// @brief a と b が同じグループに属すかを返します。
    /// @param a 一方のインデックス
    /// @param b 他方のインデックス
    /// @return a と b が同じグループに属す場合 true, それ以外の場合は false
    bool connected(int a, int b) { return (find(a) == find(b)); }

    /// @brief i が属するグループの要素数を返します。
    /// @param i インデックス
    /// @return i が属するグループの要素数
    int size(int i) { return -m_parentsOrSize[find(i)]; }

   private:
    // m_parentsOrSize[i] は i の 親,
    // ただし root の場合は (-1 * そのグループに属する要素数)
    std::vector<int> m_parentsOrSize;
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
    int N, M, K;
    cin >> N >> M >> K;

    unordered_map<int, unordered_set<int>> degree;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        degree[u].insert(v);
        degree[v].insert(u);
    }

    set<int> ans;
    vector<int> aho(K);
    vector<int> hp(K);
    rep(i, K) {
        cin >> aho[i];
        cin >> hp[i];
    }

    rep(i, K) {
        ans.insert(aho[i]);
        queue<int> q;
        q.push(aho[i]);
        while (hp[i] > 0) {
            hp[i]--;
            while (!q.empty()) {
                int tmp = q.front();
                q.pop();
                for (auto itr = degree[tmp].begin(); itr != degree[tmp].end();
                     itr++) {
                    ans.insert(*itr);
                    q.push(*itr);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for (auto itr = ans.begin(); itr != ans.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}
