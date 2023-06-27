#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = n; i > (int)(n); i--)
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
const int LMT = 1980; // ミリ秒指定

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

int N = 30;

int K = 0;
vector<vector<int>> ans(100001, vector<int>(4));
vector<vector<int>> ball(N, vector<int>(N, INF));

void ans_writer(int x0, int y0, int x1, int y1){
    ans[K][0] = x0;
    ans[K][1] = y0;
    ans[K][2] = x1;
    ans[K][3] = y1;
    K++;
}

void output(){
    print(K);
    rep(i, K){
        rep(k, 4){
            cout << ans[i][k] << " ";
       }
        cout << endl;
    }
}


// 貪欲解で使っていたもの もったいないので残している
bool ball_swap(int i, int k){
    int h[4] = {-1, -1, -1, -1};    
    if(i != 0 && k > 0){
        if(ball[i][k] < ball[i-1][k-1]) h[0] = abs(ball[i][k] - ball[i-1][k-1]);
    }
    if(i != 0 && ball[i-1][k] != INF){
        if(ball[i][k] < ball[i-1][k]) h[1] = abs(ball[i][k] - ball[i-1][k]);
    }
    int acp = -1;
    int maxH = -1;
    rep(fff, 2){
        if(h[fff] != -1){
            if(chmax(maxH, h[fff])){
                acp = fff;
            }
        }
    }
    
    if(acp == 0){
        swap(ball[i][k], ball[i-1][k-1]);
        ans_writer(i, k, i-1, k-1);
        ball_swap(i-1, k-1);
        return false;
    }else if(acp == 1){ 
        swap(ball[i][k], ball[i-1][k]);
        ans_writer(i, k, i-1,k);
        ball_swap(i-1, k);
        return false;
    }    
    return true;
}


void print_dp(vector<vector<pair<int, int>>> &vec){
    rep(i, N){
        rep(k, N){
            if(vec[i][k].first == N_INF) cout << "----- ";
            else cout << vec[i][k].first << "-" << vec[i][k].second << " ";
        }
        print(" ");
    }
}

// なんでビムサしようとしてDP書いてるんですか？？？アホ？？？？？？？？？？？？？？？？
void beam(int start_i, int start_k){
    vector<vector<pair<int, int>>> dp(N, vector<pair<int, int>>(N, {N_INF, INF}));
    dp[start_i][start_k] = {0, -1};
    stack<tuple<int, int, int, int>> st;
    int top = -1;
    set<int> end;

    for(int to_top = N-1; to_top >= 0; to_top--){
        top = to_top;
        rep(to_side, N){
            bool flag = false;
            if(dp[to_top][to_side].first == N_INF)continue;
            if(to_top > 0 && to_side > 0){
                if(ball[start_i][start_k] < ball[to_top-1][to_side-1]) {
                    flag = true;
                    if(chmax(dp[to_top-1][to_side-1].first, dp[to_top][to_side].first + power(abs(ball[start_i][start_k] - ball[to_top-1][to_side-1]), 1))){
                        dp[to_top-1][to_side-1].second = to_side;
                    }
                }
            }
            if(to_top > 0 && ball[to_top-1][to_side] != INF){
                if(ball[start_i][start_k] < ball[to_top-1][to_side]) {
                    flag = true;
                    if(chmax(dp[to_top-1][to_side].first, dp[to_top][to_side].first + power(abs(ball[start_i][start_k] - ball[to_top-1][to_side]), 1))){
                        dp[to_top-1][to_side].second = to_side;
                    }
                }
            }
            if(!flag) {end.insert(to_side);}
        }
        if(!end.empty())break;
    } 
  
    int next_k, start_max = N_INF+1;
    if(top == -1) {
        // print(ball[start_i][start_k]);
        return;
    }

    for(int i = 0; i < N; i++){
        if(end.count(i)==1)if(chmax(start_max, dp[top][i].first)) next_k = i;
    }
    for(int i = top; i < N-1; i++){
        if(dp[i][next_k].second == -1)break;
        st.push({i, next_k, i+1 ,dp[i][next_k].second});
        next_k = dp[i][next_k].second;
    }
    while(!st.empty()){
        auto p = st.top();
        st.pop();
/*         print(get<0>(p) << " " << get<1>(p) << " "<<  get<2>(p) << " "<< get<3>(p)); */
        ans_writer(get<0>(p), get<1>(p), get<2>(p), get<3>(p));
        swap(ball[get<0>(p)][get<1>(p)], ball[get<2>(p)][get<3>(p)]);
    }
}

void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();
    rep(i, N){
        rep(k, i+1){
            cin >> ball[i][k];
        }
    } 
    // while(true){
    rep(now, 465){
        rep(i, N){
            rep(k, i+1){
                if(ball[i][k] == now){
                    if(now == ball[i][k]){
                        beam(i, k);
                    }
                }
            }
        }
    // } 
    end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count(); //処理に要した時間をミリ秒に変換}
    if(elapsed > LMT) break;
    }
    output();
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
