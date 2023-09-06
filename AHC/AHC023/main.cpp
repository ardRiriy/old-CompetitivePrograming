#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
const int LMT = 2000; // ミリ秒指定


bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }

int h = 20, w = 20;
int t, enter;
int dx[4] = {0, -1, 0 , 1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<int>> south_water_route(h-1, vector<int>(w)); // そのマスの座標(i, j)の下に水路があるかどうか
vector<vector<int>> east_water_route(h, vector<int>(w-1)); //そのマスの右に水路があるかどうか
vector<vector<int>> board(h, vector<int>(w, -1));
vector<vector<int>> depth(h, vector<int>(w, INF));
vector<vector<int>> sd;

struct Pos{
    int h;
    int w;
};

struct Plan{
    int i;
    Pos p;
    int s;
};

// board[i][j] -> Edge[i * w + j]と対応
class LowLink {
    typedef vector<vector<int>> Edge; // i番目の頂点と隣接なブロックの列
    vector<bool> visited; // 訪問したかの管理
    vector<int> order; //順序
    vector<int> low; //low[親] < low[子]ならブリッジとなる．そうなんだ
    public:
        Edge E; // 与えられる木
        vector<int> articulation_point; // 関節点
        vector<pair<int, int>> bridge;
    private:
        void dfs(int now, int parent, int& count){
            visited[now] = true;
            order[now] = count;
            low[now] = order[now];
            count++;
            bool is_art = false; // 関節点かどうかを保存
            int son_count = 0;
            for(auto next: E[now]){
                if(!visited[next]){
                    son_count++;
                    dfs(next, now, count);
                    if(next != parent){
                        low[now] = min(low[now], low[next]);
                    }
                    if(parent != -1 && order[now] <= low[next]){
                        is_art = true;
                    }
                    if(order[now] < low[next]){
                        bridge.push_back({min(now, next), max(now, next)});
                    }
                }else{
                    if(next != parent){
                        low[now] = min(low[now], order[next]);
                    }
                }
            }
            if(parent == -1 && son_count >= 2){
                is_art = true;
            }
            if(is_art){
                articulation_point.push_back(now);
            }
        }
    public:
    /**
    * 渡すのは隣接リスト形式のグラフ。辺の長さは受け付けない.
    *
    * \param e
    */
    LowLink(const Edge& e) {
        E = e;
        visited.assign(E.size(), 0);
        order.assign(E.size(), 0);
        low.assign(E.size(), 0);
    }
    /**
    * 計算の際に呼び出す。各連結成分ごとにDFSしている。.
    *
    */
    void build() {
        // 既存の結果と状態をクリア
        visited.assign(E.size(), 0);
        order.assign(E.size(), 0);
        low.assign(E.size(), 0);
        articulation_point.clear();
        bridge.clear();

        int count = 0;
        for (int i = 0; i < E.size(); i++) {
            if (!visited[i])
                dfs(i, -1, count);
        }
    }

    void addEdge(int u, int v) {
        E[u].push_back(v);
        E[v].push_back(u);
    }

    void removeEdge(int u, int v) {
        E[u].erase(remove(E[u].begin(), E[u].end(), v), E[u].end());
        E[v].erase(remove(E[v].begin(), E[v].end(), u), E[v].end());
    }
};

bool is_through(Pos p, int r){
    int new_h = p.h + dy[r];
    int new_w = p.w + dx[r];

    if (new_h < 0 || new_h >= h || new_w < 0 || new_w >= w) {
        return false;
    }

    // 水路のチェック
    if (r % 2 == 0) { // 上または下
        if (south_water_route[min(p.h, new_h)][p.w] != 0) {
            return false;
        }
    } else { // 左または右
        if (east_water_route[p.h][min(p.w, new_w)] != 0) {
            return false;
        }
    }
    return true;
}

bool is_reachable_to_enter(Pos p, vector<vector<int>> &bd){
    queue<Pos> que;
    que.push(p);
    vector<vector<bool>> is_checked(h, vector<bool>(w, false));
    is_checked[p.h][p.w] = true;
    while(!que.empty()){
        auto now = que.front();
        que.pop();
        rep(i, 4){
            Pos next;
            next.h = now.h + dy[i], next.w = now.w + dx[i];
            if(is_through(now, i) && !is_checked[next.h][next.w] ){
                if(bd[next.h][next.w] == -1){
                    if(next.h == enter && next.w == 0) return true;
                    is_checked[next.h][next.w] = true;
                    que.push(next);
                }
            }
        }
    }
    return false;
}

vector<vector<int>> make_linked_list(vector<vector<int>> &bd){
    vector<vector<int>> res(h * w);
    rep(i,h){
        rep(j, w){
            rep(r, 4){
                if(!is_through({i, j}, r)) continue;
                int new_h = i + dy[r];
                int new_w = j + dx[r];
                if(bd[new_h][new_w] == -1) res[i * w + j].push_back(new_h * w + new_w);
            }
        }
    }
    return res;
}


void calc_depth(Pos start, vector<vector<int>>&bd){
    queue<pair<Pos, int>> que;
    fill(depth.begin(), depth.end(), vector<int>(w, INF));
    int now = 0;
    depth[start.h][start.w] = now;
    que.push({start, now});

    while(!que.empty()){
        auto a = que.front();
        que.pop();
        Pos p = a.first;
        int n = a.second;
        rep(i, 4){
            if(!is_through(p, i)) continue;
            int new_h = p.h + dy[i];
            int new_w = p.w + dx[i];

            // boardのチェック
            if (bd[new_h][new_w] != -1) {
                continue;
            }
            // depthの更新
            if (depth[new_h][new_w] == INF) {
                que.push({{new_h, new_w}, n + 1});
                depth[new_h][new_w] = n + 1;
            }
        }
    }
}

bool is_placable(Pos p, vector<int> &v, int proceed_day, vector<vector<int>> &bd){
    if(bd[p.h][p.w] != -1 || depth[p.h][p.w] == INF || (p.h == enter && p.w ==  0)) return false;

    rep(i, 4){
        if(!is_through(p, i)) continue;
        Pos next;
        next.h = p.h + dy[i], next.w =p.w + dx[i];
        if(bd[next.h][next.w] == -1) continue;
        if(proceed_day > sd[bd[next.h][next.w]-1][1]){
            bd[p.h][p.w] = 100;
            if(!is_reachable_to_enter(next, board)) {
                bd[p.h][p.w] = -1;
                return false;
            }
            bd[p.h][p.w] = -1;
        }
    }

    for(auto i: v) if(p.h * w + p.w == i) return false;
    return true;
}

int manhattan_distance_from_wall(Pos p){
    return pow(enter - p.h, 2) + pow(p.w , 2);
}


int calcu_value(int crop_num, Pos p, vector<vector<int>> bd){
    int proceed_day = sd[crop_num - 1][1] - sd[crop_num - 1][0];
    int value = 0;

    // 小さい数字は手前に入ってほしいという気持ちをこめている
    if(proceed_day <= 7) value += pow(depth[p.h][p.w], 2);

    rep(i, 4){
        if(is_through(p, i)){
            int nh = p.h + dy[i], nw = p.w + dx[i];
            if(bd[nh][nw] == -1) value += proceed_day;
            else value += abs(sd[crop_num - 1][1] - sd[bd[nh][nw] - 1][1]);
        }
    }
    return value;
}

/*主に作物の取り除き時に利用*/
void add_lowlink_edge(Pos p, LowLink &ll, vector<vector<int>> &bd){
    rep(i, 4){
        int nh = p.h + dy[i], nw = p.w + dx[i];
        if(is_through(p, i) && bd[nh][nw] == -1){
            ll.addEdge(p.h * w + p.w, nh * w + nw);
        }
    }
    ll.build();
}

/*主に植付時に利用*/
void remove_lowlink_edge(Pos p, LowLink &ll, vector<vector<int>> &bd){
    rep(i, 4){
        int nh = p.h + dy[i], nw = p.w + dx[i];
        if(is_through(p, i) && bd[nh][nw] == -1){
            ll.removeEdge(p.h * w + p.w, nh * w + nw);
        }
    }
    ll.build();
}
void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();
    cin >> t >> h >> w >> enter;

    vector<vector<bool>> isChecked(h, vector<bool>(w, false));

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

    int k;
    cin >> k;
    map<int, vector<pair<int, int>>> data;
    sd.resize(k, vector<int>(2));
    rep(i, k){
        cin >> sd[i][0] >> sd[i][1];
        data[sd[i][0]].push_back({sd[i][1], i+1});
    }
    
    board.resize(h, vector<int>(w, -1));
    calc_depth({enter, 0}, board);

    rep(i, t) sort(data[i+1].begin(), data[i+1].end());
    vector<Plan> ans;

    auto g = make_linked_list(board);    
    LowLink lowlink(g);
    lowlink.build();

    for(int month = 1; month <= t;month++){
        // 通常植付フェーズ
        for(auto itr = data[month].rbegin(); itr != data[month].rend(); itr++){
            auto c = *itr;

            Pos option = {-1, -1};
            int perf = 1e5;
            rep(i, h){
                rep(j, w){
                    if(is_placable({i, j}, lowlink.articulation_point, c.first, board)){
                        int t_v = calcu_value(c.second, {i, j}, board);
                        if(chmin(perf, t_v)){
                            option = {i, j};
                        }else if(perf == t_v){
                            if(depth[i][j] < depth[option.h][option.w]){
                                option = {i, j};
                            }
                        }
                    }         
                }
            }
            if(option.h != -1){
                board[option.h][option.w] = c.second;
                remove_lowlink_edge(option, lowlink, board);
                ans.push_back({board[option.h][option.w], option, month});
            }
        }

        //収穫
        queue<Pos> que;
        que.push({enter, 0});

        fill(isChecked.begin(), isChecked.end(), vector<bool>(w, false));
        while(!que.empty()){
            auto p = que.front();
            que.pop();
            rep(i, 4){
                if(!is_through(p, i)) continue;

                int new_h = p.h + dy[i];
                int new_w = p.w + dx[i];
                if(isChecked[new_h][new_w]) continue;
                // boardのチェック
                int crop_num = board[new_h][new_w];
                if (crop_num == -1) {
                    que.push({new_h, new_w});
                    isChecked[new_h][new_w] = true;
                }else if(sd[crop_num-1][1] <= month){
                    board[new_h][new_w] = -1;
                    add_lowlink_edge({new_h, new_w}, lowlink, board);
                    que.push({new_h, new_w});
                    isChecked[new_h][new_w] = true;
                }
            }
        }
    }

    print(ans.size());
    rep(i, ans.size()){
        print(ans[i].i<< " " << ans[i].p.h << " " << ans[i].p.w << " " <<ans[i].s);
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
