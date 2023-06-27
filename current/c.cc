#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;

class UnionFind { 
    private: vector<int> uf;
    public:
    UnionFind(int size) : uf(size) { for (int i = 0; i < size; i++) uf[i] = -1; }
    int root(int n) { if (uf[n] < 0) return n; else return uf[n] = root(uf[n]); }
    bool connected(int a, int b) { return root(a) == root(b); }
    void marge(int a, int b) { int root_a = root(a); int root_b = root(b); if (root_a != root_b) { if (uf[root_a] > uf[root_b]) swap(root_a, root_b); uf[root_a] += uf[root_b]; uf[root_b] = root_a; }}
    int size(int n) { return -uf[root(n)]; }
};
bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int base, int exponent) {int result = 1;for (int i = 0; i < exponent; i++) result *= base; return result; }
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

int n;
int win_count;

int win_num(vector<int> &vec){
    int win = 0;
    rep(i, vec.size()){
        if(vec[i] == 1) win++;
    }
    return win;
}

int lose_num(vector<int> &vec){
    int lose = 0;
    rep(i, vec.size()){
        if(vec[i] == 0) lose++;
    }
    return lose;
}

int dfs(vector<vector<int>> vec, int x, int y){
    int ans = 0;
    int now_x_win = win_num(vec[x]);
    int now_x_lose = lose_num(vec[x]);
    if(x == n-1 && y == n-1){
        if(now_x_win != win_count) return 0;
        return 1;
    }

    // 枝刈
    if(now_x_win > win_count || now_x_lose > win_count) return 0;
    else if (now_x_win == win_count){
        rep(i, n){
            if(vec[x][i] == INF) {
                vec[x][i] = 0;
                vec[i][x] = 1;
            }
        }
    }else if ( now_x_lose == win_count){
        rep(i, n){
            if(vec[x][i] == INF) {
                vec[x][i] = 1;
                vec[i][x] = 0;
            }
        }
    }

    // まだ結果が不定
    if(vec[x][y] == INF){
        // xがyに勝つ
        vec[x][y] = 1;
        vec[y][x] = 0;
        if(y == n-1) ans += dfs(vec, x+1, 0);
        else ans += dfs(vec, x, y+1);
    
        // xがyに負ける
        vec[x][y] = 0;
        vec[y][x] = 1;
        if(y == n-1) ans += dfs(vec, x+1, 0);
        else ans += dfs(vec, x, y+1);
    }else{
        if(y == n-1) ans += dfs(vec, x+1, 0);
        else ans += dfs(vec, x, y+1);
    }

    return ans;
}

void solve() {
    while(true){
/*         std::chrono::system_clock::time_point  start, end;
        start = std::chrono::system_clock::now(); */
        cin >> n;
        if(n == 0) return;
        win_count = n/2;
        int m;
        cin >> m;

        vector<vector<int> > vec(n, vector<int>(n, INF));

        rep(i, n){
            vec[i][i] = -1;
        }

        rep(i, m){
            int x, y;
            cin >> x >> y;
            x--;y--;
            vec[x][y] = 1;
            vec[y][x] = 0;
        }
        print(dfs(vec, 0, 0));
/*         end = std::chrono::system_clock::now();
        double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
        print(elapsed << "ms."); */
    }
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
