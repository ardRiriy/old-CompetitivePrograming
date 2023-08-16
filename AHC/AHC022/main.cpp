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
const int BEAM_WITDH = 750;
const bool DEBUG_MODE = false;
const int MEASURE_NUM = 6;
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

struct Beam {
    int evaluation;
    vector<bool> state;
    vector<int> correspondences;
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

    double a = -4000.0 / l / l;
    double b = 4000.0 / l;
    int temp = a * x * x + round(b * x);
/*     print("# " << a << " " << b << " "<< x << " " << temp); */
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
    rep(i, MEASURE_NUM) sum += abs(r1.t[i] - r2.t[i]);
    return sum;
}

void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();

    
    cin >> l >> n >> s;

    MEASURE_TIMES = max((int)1, min(power((int)s / 10, 2), (int)1e4 / (MEASURE_NUM * n))); 
    exit_cell.resize(n);
    temperature.resize(l, vector<int>(l, -1));
    
    rep(i, n){
        cin >> exit_cell[i].y >> exit_cell[i].x;
    }
    
    decide_temperature(temperature, {(int)l/2, (int)l/2});

    print_grid(temperature);

    DEBUG_INPUT();
    // 計測
    vector<Results> rs(n);
    vector<Results> true_value(n);
    int dy[MEASURE_NUM] = {0, -2, -2, 0, 0, 2};
    int dx[MEASURE_NUM] = {0, 0, 2, -2, 2, 0};
    rep(i, n){
        rs[i].t.resize(MEASURE_NUM, 0);
        true_value[i].t.resize(MEASURE_NUM, 0);
        rep(j, MEASURE_NUM){
            rep(k, MEASURE_TIMES){
                int tmp = question(i, dy[j], dx[j]);
                rs[i].t[j] += tmp;
            }
            rs[i].t[j] = round(rs[i].t[j] / MEASURE_TIMES);
            true_value[i].t[j] = temperature[(exit_cell[i].y + dy[j] + l) % l][(exit_cell[i].x + dx[j] + l) % l];
        }
    }


    vector<Beam> beam_a, beam_b;
    /*初期状態を作る*/
    rep(i, n){
        Beam beam;
        beam.evaluation = temperature_diff(rs[0], true_value[i]);
        beam.state.resize(n, false);
        beam.state[i] = true;
        beam.correspondences.push_back({i});
        beam_a.push_back(beam);
    }

    for(int i = 1; i < n; i++){
        if(i % 2 == 1){
            // beam_a -> beam_bに遷移
            rep(j, min(BEAM_WITDH, (int)beam_a.size())){
                rep(k, n){
                    Beam tmp = beam_a[j];
                    if(tmp.state[k]) continue;
                    tmp.state[k] = true;
                    tmp.correspondences.push_back(k);
                    tmp.evaluation += temperature_diff(rs[i], true_value[k]);
                    beam_b.push_back(tmp);
                }
            }
            sort(beam_b.begin(), beam_b.end(),
                [](const Beam& a, const Beam& b) {
                    return a.evaluation < b.evaluation; 
                });
            beam_a.clear();
        }else{
            // beam_b -> beam_aに遷移
            rep(j, min(BEAM_WITDH, (int)beam_b.size())){
                rep(k, n){
                    Beam tmp = beam_b[j];
                    if(tmp.state[k]) continue;
                    tmp.state[k] = true;
                    tmp.correspondences.push_back(k);
                    tmp.evaluation += temperature_diff(rs[i], true_value[k]);
                    beam_a.push_back(tmp);
                }
            }
            sort(beam_a.begin(), beam_a.end(),
                [](const Beam& a, const Beam& b) {
                    return a.evaluation < b.evaluation; 
                });
            beam_b.clear();
        }
    }

    //回答
    print("-1 -1 -1");
    if(!beam_a.empty()){
        rep(i, n){
            print(beam_a[0].correspondences[i]);
        }
    }else{
        rep(i, n){
            print(beam_b[0].correspondences[i]);
        }
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
