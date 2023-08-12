#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int LMT = 3600; // ミリ秒指定
const int MEASURE_TIMES = 8; // 計る回数
const int ACCEPTABLE_ERROR = 20; // 許容しうる温度の誤差(初期解)
const int QUESTION_LIMIT = 10000;
using namespace std;

bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int base, int exponent) {int result = 1;for (int i = 0; i < exponent; i++) result *= base; return result; }

struct Pos{
    int y;
    int x;
};

vector<int> a;
vector<Pos> exit_cell;
vector<vector<int>> temperature;
int l, n, s;
int q_cnt = 0;

void print_grid(vector<vector<int>> &v){
    rep(i, v.size()){
        rep(j, v[i].size()){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int question(int wormhole, int y, int x){
    print(wormhole << " " << y << " " << x);
    int m;
    cin >> m;
    q_cnt++;
    // debug用(提出時につける)
    /* if(m ==  -1) exit(1); */
    return m;
}

vector<int> memo(100, -1);
int temperature_fanction(int x){
    if(memo[x] != -1) return memo[x];

    int temp = -power(x, 2) + l * x;
    temp = temp *  160 / 100;
    print("# " << x << " " << temp);
    memo[x] = min((int) 1000, max((int) 0, temp));
    return memo[x];
}

void decide_temperature(vector<vector<int>> &v, Pos first_pos){
    rep(i, l){
        rep(j, l){
            v[i][j] = (temperature_fanction(i) + temperature_fanction(j)) / 2;
        }
    }
}

int decide_exit(vector<int> &exits, int whormhole){


    int Q = 5;  
    int dx[5] = {1,-1, 0, 0, 0};
    int dy[5] = {0, 0, 1, -1, 0};
    vector<int> temp(5, 0);

    
    //温度計測
    rep(i, 5){
        rep(j, Q){
            if(q_cnt >= QUESTION_LIMIT) break;
            temp[i] += question(whormhole, dy[i], dx[i]);
            // debug用
            temp[i] += a[whormhole];
            

            cout << "# TP: " << whormhole << " ";
            for(int i: exits) cout << i << " ";
            print("");

        } 
        temp[i] = round(temp[i] / Q);
    }

    int min_diff = INF;
    int min_idx = 0;
    rep(i, exits.size()){
        int diff_sum = 0;
        rep(j, 5){
            int t_x =(exit_cell[exits[i]].y + dy[j]) % l;
            int t_y = (exit_cell[exits[i]].x + dx[j]) % l;
            if(t_x < 0) t_x += l;
            if(t_y < 0) t_y += l;
            diff_sum += abs(temperature[t_x][t_y] - temp[j]);
        }
        if(chmin(min_diff, diff_sum)){
            min_idx = i;
        }
    }
    return exits[min_idx];
}


void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();

    
    cin >> l >> n >> s;

    exit_cell.resize(n);
    temperature.resize(l, vector<int>(l, -1));
    
    rep(i, n){
        cin >> exit_cell[i].y >> exit_cell[i].x;
    }
    
    decide_temperature(temperature, {(int)l/2, (int)l/2});

    print_grid(temperature);

    // debug用(提出時に消す)
    a.resize(n);
    rep(i, n) cin >> a[i];

    
    // 計測
    vector<int> measure(n, 0), ans(n, 0);
    map<int, vector<int>> list;

    rep(i, n){
        rep(j, MEASURE_TIMES){
            if(q_cnt >= QUESTION_LIMIT) break;
            measure[i] += question(i, 0, 0);
            
            // debug用 提出時に消す
            measure[i] += temperature[exit_cell[a[i]].y][exit_cell[a[i]].x];

        }
        measure[i] = round(measure[i] / MEASURE_TIMES);

        rep(j, n){
            if(abs(temperature[exit_cell[j].y][exit_cell[j].x] - measure[i]) < ACCEPTABLE_ERROR){
                list[i].push_back(j);
            }
        }
    }

    rep(i, n){
        if(list[i].size() != 0) ans[i] = decide_exit(list[i], i);
    }

    //回答
    print("-1 -1 -1");
    rep(i, n){
        print(ans[i]);
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
