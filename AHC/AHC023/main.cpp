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

/** timeline
 * [正の点数を得たいパート]
 * 作物を植える位置 -> 収穫時期が遅いものほど奥に
 * ↓
 * いったんすべて度外視で，「Dが大きいものから順に奥に」を実装する -> DONE(6317350)
 * ----------------------------------------------------
 * [改善part1]
 * これの位置決めるの，terryさんのブログで見たやつだな...
 * delta = (ある地点の深さ) - (その作物の収穫時期)として
 * 
 * delta >= 0 -> delta
 * delta < 0 -4delta
 * 関節点にはおいたらダメ -> lowlinkってやつですか(これもterryさんのブログで見たやつだな)(参考にしすぎでは？)(いつもRTお世話になっております)
 * 
 * 結構よくなった(13306975)
 * ----------------------------------------------------
 * [改善できそうなところ]
 * - 置く位置に制限をかける
 *  - 例えば，成長しきるまでにかかる日数 + 15の深さまでしか置けないとか
 *  -> 没 これをすると深い位置の区画が腐ってしまう
 * 
 * - BFSの更新
 *  - これは実行時間がきついとか試行回数稼ぎたいとかの時にやる
 *  -> DONE(というか，もろもろの改善と合わせてdepthは一回のみ更新に変わったので不要になった)
 *
 * - 月の後半のほうの配置
 *  - 最後のほうは適当においてもまぁまぁ行ける
 * 
 * - isPlacableを改善
 *  - 「その位置よりも深い位置に，自分より先に収穫する値があってはいけない」みたいな． 
 *  - DONE (DFSするとむしろ点が下がったので，周囲4マスだけ見るようにした)
 *
 * - 貪欲だときつそう？
 *  - まぁヒュだしな...
 *  - やるならビムサな気がするけど，どうだろう 
 * 
 * - うまくいかないケースはだいたい奥のほうが腐ってる
 * - 手前からBFSして決定してくのはどうか？
 *  - 没 下がる(なぜ？)
 * 
 * - 確率で現在よりも後の月に植え付ける作物を先に植え付けてしまうのはどうか？
 *  - 基本的な狙いとしては配置場所がなくて数字が大きいものが置けなくなる(結果特に後半で空きスペースが増える)ことを防ぎたい気持ち
 *  - 今のところ取り入れると強そうではある(が，ビムサの処理が大変になりそう)
 * 
 * - 前半の方ほどデカい数字を先に置いたほうがよさげ？
 *  - 先取してくる量を増やすか
 *  -  没 そんな変わらん
 * 
 * - 道が確保できるなら別に手前にデカい数字が来てもいい
 *  - 奥に小さい数字が来るのはうれしくない
 * 
 * - 単純に全部埋まってたほうが強い
 *  - 平均で埋まってる率が高い順みたいなビムサはどうか？
 * -----------------------------------------------------
 * [改善中]
 * - isPlacable改善 -> ちょっと良くなった(14995525)
 *  - もっと深い位置まで検索したほうが良いんだろうけどいったんパス
 * 
 * - 気持ち置くめにおいてもいいことにした
 *  - かなり改善(21122450)
 *
 * - 隣接4マスに自分より先に収穫するものが入っていたら置かないようにした(dfsがうまくいかなかった顔)
 *  - 暫定テスト: 34730425(https://atcoder.jp/contests/ahc023/submissions/45230794)
 * 
 * - とりあえず10か月先まで見て先取で置いてみる
 *  - 暫定テスト: 34045100(https://atcoder.jp/contests/ahc023/submissions/45231216)
 *  - ？＿？
 * ----------------------------------------------------------
 * [Twitter] 
 * - >__< ← 行き詰ったからAzureでローカル実行環境を作ろうとしている顔
 *  よくわからんからデスクトップでGitPullすればいいかｗ
 * 
 * - 深さの再計算やめたら早くなった
 *  - 点数は大して変わらなそうなので，早いほうが良いね
 * 
 * - デスクトップで1000ケース実行したら爆速になってワロタ
 *  - 今のところ提出の手元実行でかなり乖離があるから，あんまり提出結果は信用ならなそう(偏ってそう)
 * 
 * - 手元ケース実行の得点計算でバグらせてたことが判明した．さすがにおもろいか
*/
int h = 20, w = 20;
int t, enter;
int dx[4] = {0, -1, 0 , 1};
int dy[4] = {-1, 0, 1, 0};

vector<vector<int>> south_water_route(h-1, vector<int>(w)); // そのマスの座標(i, j)の下に水路があるかどうか
vector<vector<int>> east_water_route(h, vector<int>(w-1)); //そのマスの右に水路があるかどうか
vector<vector<int>> board(h, vector<int>(w, -1));
vector<vector<int>> depth(h, vector<int>(w, INF));
vector<vector<int>> sd;


void print_grid(vector<vector<int>>& vec){
    rep(i, h){
        rep(j, w){
            cout << vec[i][j] << " ";
        }
        print("");
    }
}

/*--------------↑debug用↑--------------------*/


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
        int count = 0;
        for (int i = 0; i < E.size(); i++) {
            if (!visited[i])
                dfs(i, -1, count);
        }
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

vector<vector<int>> make_linked_list(){
    vector<vector<int>> res(h * w);
    rep(i,h){
        rep(j, w){
            rep(r, 4){
                if(!is_through({i, j}, r)) continue;
                int new_h = i + dy[r];
                int new_w = j + dx[r];
                if(board[new_h][new_w] == -1) res[i * w + j].push_back(new_h * w + new_w);
            }
        }
    }
    return res;
}


void update_depth(Pos start){
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
            if (board[new_h][new_w] != -1) {
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


bool is_placable(Pos p, vector<int> &v, int proceed_day){
    if(board[p.h][p.w] != -1 || depth[p.h][p.w] == INF || (p.h == enter && p.w ==  0)) return false;

    rep(i, 4){
        if(!is_through(p, i)) continue;
        if(board[p.h + dy[i]][p.w + dx[i]] == -1) continue;
        if(proceed_day > sd[board[p.h + dy[i]][p.w + dx[i]]-1][1]) return false;
    }


    for(auto i: v) if(p.h * w + p.w == i) return false;
    return true;
}

int manhattan_distance_from_wall(Pos p){
    return pow(enter - p.h, 2) + pow(p.w , 2);
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
    update_depth({enter, 0});

    int MOST_DEEP = 1; 
    rep(i, h) rep(j, w) if(depth[i][j] != INF) chmax(MOST_DEEP, depth[i][j]);

    vector<Plan> ans;

    rep(i, t){
        sort(data[i+1].begin(), data[i+1].end());
    }

    for(int month = 1; month <= t;month++){
        //植付

        // 先取植付フェーズ
        for(int diff = min(month + 2, t); diff > month; diff--){
            rep(i, 2){
                if(data[diff].empty() || data[month].empty()) continue;
                auto max_now = *data[month].rbegin();
                auto tmp = *data[diff].rbegin();
                if(max_now.first < tmp.first){
                    data[month].push_back(tmp);
                    data[diff].pop_back();
                }
            }
        }

        // 通常植付フェーズ
        for(auto itr = data[month].rbegin(); itr != data[month].rend(); itr++){
            auto c = *itr;
            auto g = make_linked_list();    
            LowLink lowlink(g);
            lowlink.build();

            Pos option = {-1, -1};
            int perf = 1e5;
            rep(i, h){
                rep(j, w){
                    if(is_placable({i, j}, lowlink.articulation_point, c.first)){
                        int proceed_day = c.first - month;
                        int t_v = depth[i][j] - proceed_day;
                        if(t_v < 0) t_v *= (-2);
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
