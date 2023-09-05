#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
const int LMT = 2000; // ミリ秒指定

using namespace std;

bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }

/**
 * 作物を植える位置 -> 収穫時期が遅いものほど奥に
 * ↓
 * いったんすべて度外視で，「Dが大きいものから順に奥に」を実装する
*/
int h = 20, w = 20;
vector<vector<int>> south_water_route(h-1, vector<int>(w)); // そのマスの座標(i, j)の下に水路があるかどうか
vector<vector<int>> east_water_route(h, vector<int>(w-1)); //そのマスの右に水路があるかどうか
int t, i0;
vector<vector<int>> board(h, vector<int>(w, -1));
vector<vector<int>> depth(h, vector<int>(w, INF));

struct Pos{
    int h;
    int w;
};

struct Plan{
    int i;
    Pos p;
    int s;
};

void print_grid(vector<vector<int>>& vec){
    rep(i, h){
        rep(j, w){
            cout << vec[i][j] << " ";
        }
        print("");
    }
}

void update_depth(Pos start){
    queue<pair<Pos, int>> que;
    int now = 1;
    que.push({start, now});

    while(!que.empty()){
        auto a = que.front();
        que.pop();
        Pos p = a.first;
        int n = a.second;
        depth[p.h][p.w] = n;

        // 右
        if(p.w < w-1 && east_water_route[p.h][p.w] == 0){
            if(depth[p.h][p.w+1] == INF){
                que.push({{p.h, p.w+1}, n+1});
                depth[p.h][p.w+1] = -1;
            }
        }
        // 下
        if(p.h < h-1 && south_water_route[p.h][p.w] == 0){
            if(depth[p.h+1][p.w] == INF){
                que.push({{p.h+1, p.w}, n+1});
                depth[p.h+1][p.w] = -1;
            }
        }
        // 左
        if(p.w > 0 && east_water_route[p.h][p.w - 1] == 0){
            if(depth[p.h][p.w-1] == INF){
                que.push({{p.h, p.w-1}, n+1});
                depth[p.h][p.w-1] = -1;
            }
        }
        if(p.h > 0 && south_water_route[p.h - 1][p.w] == 0){
            if(depth[p.h-1][p.w] == INF){
                que.push({{p.h-1, p.w}, n+1});
                depth[p.h-1][p.w] = -1;
            }
        }
    }
}

Pos max_in_depth(){
    int max = N_INF;
    Pos res = {-1, -1};
    rep(i, h){
        rep(j, w){
            if(board[i][j] == -1 && chmax(max, depth[i][j])){
                res = {i, j};
            }
        }
    }
    if(res.h != -1)board[res.h][res.w] = 1;
    return res;
}

void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();
    cin >> t >> h >> w >> i0;
    rep(i, h-1){
        string s;
        cin >> s;
        rep(j, w) south_water_route[i][j] = s[j] - '0';
    }
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w-1) east_water_route[i][j] = s[j] - '0';
    }
    
    update_depth({i0, 0});
    int k;
    cin >> k;
    vector<vector<int>> sd(k, vector<int>(2));
    rep(i, k){
        cin >> sd[i][0] >> sd[i][1];
    }
    
    int month = t;
    vector<Plan> ans;
    
    while(month > 0){
        rep(i, k){
            if(sd[i][1] == month){
                Pos p = max_in_depth();
                if(p.h != -1) ans.push_back({i, p, 1});
                
            }
        }
        month--;
    }

    print(ans.size());
    rep(i, ans.size()){
        print(ans[i].i + 1<< " " << ans[i].p.h << " " << ans[i].p.w << " " <<ans[i].s);

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
