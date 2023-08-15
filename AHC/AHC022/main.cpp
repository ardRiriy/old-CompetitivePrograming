#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int LMT = 3600; // ミリ秒指定
const int QUESTION_LIMIT = 10000;
const bool DEBUG_MODE = false;
using namespace std;

bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int base, int exponent) {int result = 1;for (int i = 0; i < exponent; i++) result *= base; return result; }

struct Pos{
    int y;
    int x;
};

struct Results{
    vector<int> t;
};

vector<int> a;
vector<Pos> exit_cell;
int MEASURE_TIMES; // 計る回数
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

void DEBUG_INPUT(){
    if(!DEBUG_MODE) return;
    a.resize(n);
    rep(i, n) {
        cin >> a[i];
    }
}

int question(int wormhole, int y, int x){
    print(wormhole << " " << y << " " << x);
    int m;
    cin >> m;
    q_cnt++;
    if(DEBUG_MODE) {
        m += temperature[(exit_cell[a[wormhole]].y + y + l) % l][(exit_cell[a[wormhole]].x + x % l)];
        m = max((int)0, min((int)1000, m));
    }
    else if(m ==  -1) exit(1);
    return m;
}

vector<int> memo(100, -1);
int temperature_fanction(int x){
    if(memo[x] != -1) return memo[x];

    int temp = -x * x + l * x;
    int a = 4000 / l / l;
    temp = temp * a;
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

int temperature_diff(Results r1, Results r2){
    int sum = 0;
    rep(i, 9) sum += abs(r1.t[i] - r2.t[i]);
    return sum;
}

void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();

    
    cin >> l >> n >> s;

    MEASURE_TIMES = max((int)1, min(power((int)s / 10, 2), (int)8e3 / (9 * n))); 
    exit_cell.resize(n);
    temperature.resize(l, vector<int>(l, -1));
    
    rep(i, n){
        cin >> exit_cell[i].y >> exit_cell[i].x;
    }
    
    decide_temperature(temperature, {(int)l/2, (int)l/2});

    print_grid(temperature);

    DEBUG_INPUT();
    // 計測
    vector<int> ans(n, 0);
    vector<Results> rs(n);
    vector<Results> true_value(n);
    int dy[9] = {0, -1, -1, -1, 0, 0, 1, 1, 1};
    int dx[9] = {0, -1, 0, 1, -1, 1, -1, 0, 1};
    rep(i, n){
        rs[i].t.resize(9, 0);
        true_value[i].t.resize(9, 0);
        rep(j, 9){
            rep(k, MEASURE_TIMES){
                rs[i].t[j] += question(i, dy[j], dx[j]);
            }
            rs[i].t[j] = round(rs[i].t[j] / MEASURE_TIMES);
            true_value[i].t[j] = temperature[(exit_cell[i].y + dy[j] + l) % l][(exit_cell[i].x + dx[j] + l) % l];
        }
    }

    rep(i, n){
        int minimam = 1e7;
        int min_idx = -1;
        rep(j, n){
            if(chmin(minimam, temperature_diff(rs[i], true_value[j]))){
                min_idx = j;
            }
        }
        ans[i] = min_idx;
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
