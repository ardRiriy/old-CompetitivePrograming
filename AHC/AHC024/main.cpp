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
const int LMT = 1900; // ミリ秒指定
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


void print_grid(vector<vector<int>> &v){
    rep(i, v.size() - 2){
        rep(j, v.size() - 2){
            cout << v[i+1][j+1] << " ";
        }
        print("");
    }
}

bool isInsideArea(int n, int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < n);
}


bool isConnected(const vector<vector<int>>& grid, int color, vector<int> &adj) {
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    // 最初の色のセルを見つける
    int start_x = -1, start_y = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == color) {
                start_x = i;
                start_y = j;
                break;
            }
        }
        if (start_x != -1) break;
    }
    if(start_x == -1) return false;

    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    
    // DFSのスタック
    stack<pair<int, int>> stk;
    stk.push({start_x, start_y});
    visited[start_x][start_y] = true;

    set<int> new_adj;
    
    while (!stk.empty()) {
        auto p = stk.top();
        stk.pop();
        int x = p.first;
        int y = p.second;

        rep(r, 4) {
            int nx = x + dx[r], ny = y + dy[r];
            if (isInsideArea(grid.size(), nx, ny) && !visited[nx][ny] && grid[nx][ny] == color) {
                visited[nx][ny] = true;
                stk.push({nx, ny});
            }
        }
    }

    // すべての色のセルが訪問されているか確認
    rep(i, grid.size()){
        rep(j, grid.size()) {
            if (grid[i][j] == color && !visited[i][j]) {
                return false;
            }
            if(grid[i][j] == color){
                rep(r, 4){
                    int ni = i + dy[r];
                    int nj = j + dx[r];
                    if(isInsideArea(n, ni, nj)){
                        new_adj.insert(grid[ni][nj]);
                    }
                }
            }
        }
    }
   new_adj.insert(color);
    for(int i: adj){
        if(new_adj.count(i) == 0) return false;
    }

    return true;
}


void solve() {
    // hogehoge
    
    /*全然思いつかない*/
    /**
     * 隣接関係だけ残して真ん中を全部抜く
     * 許させなかった，色0も連結である必要あり
     * 
     * 右下のほうに寄せて左上を白くする作戦
    */
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();
    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換

    int n, m;
    cin >> n >> m;

    std::mt19937 generator;
    generator.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n+1);


    vector<vector<int>> bd(n+2, vector<int>(n+2, 0));
    rep(i, n) rep(j, n) cin >> bd[i+1][j+1];
    n+=2;

    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

    map<int, set<int>> adj; //adj[色][隣] = 数

    rep(i, n){
        rep(j, n){
            rep(r, 4){
                int ni = i + dy[r];
                int nj = j + dx[r];
                if(isInsideArea(n, ni, nj)){
                    adj[bd[i][j]].insert(bd[ni][nj]);
                }
            }
        }
    }
    int cnt = 0;
    while(true){
        cnt++;
        end = std::chrono::system_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換 
        if(elapsed >= LMT) break;

        int i = distribution(generator);
        int j = distribution(generator);

        
        rep(r, 4){
            int ni = i + dy[r];
            int nj = j + dx[r];
            if(abs(i - 25) + abs(j - 25) >= abs(ni - 25) + abs(nj - 25))
            if(isInsideArea(n, ni, nj)){
                if((bd[ni][nj] == 0 && distribution(generator) % 5 != 0)|| bd[ni][nj] == bd[i][j]) continue;

                vector<int> old_adj;
                bool flag = true;
                rep(k, 4){
                    int nni = ni + dy[k];
                    int nnj = nj + dx[k];
                    if(!isInsideArea(n, nni, nnj)) continue;
                    if(adj[bd[i][j]].count(bd[nni][nnj]) == 0) {
                        flag = false;
                        break;
                    }
                    old_adj.push_back(bd[nni][nnj]);
                }
                if(!flag) continue;
                int tmp = bd[ni][nj];
                bd[ni][nj] = bd[i][j];
                if(!isConnected(bd, tmp, old_adj)){
                    bd[ni][nj] = tmp;
                }
            }
        }
        if(cnt % (int)1e4 == 1) print_grid(bd);
    }

    print_grid(bd);
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
