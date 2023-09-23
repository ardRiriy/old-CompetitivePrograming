#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
const int LMT = 10000; // ミリ秒指定

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

vector<pair<int,int>> city;

void print_ans(vector<int> &ans){
    rep(i, ans.size()) print(ans[i] + 1);
}

double distance(pair<int, int> a, pair<int, int> b){
    return sqrtf64(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

double culc_score(vector<int> &vec){
    double sum = 0;
    rep(i, vec.size()-1){
        sum += distance(city[vec[i]], city[vec[i+1]]);
    }
    return sum;
}

double culc_diff_score(vector<int> &vec, int a, int b, int n){
    double score = distance(city[vec[a]], city[vec[(a+1) % n]]) + distance(city[vec[a]], city[vec[(a-1+n)%n]]) + distance(city[vec[b]], city[vec[(b+1)%n]]) + distance(city[vec[b]], city[vec[(b-1+n)%n]]);
    return score;
}


void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, now;
    start = std::chrono::system_clock::now();

    int n;
    cin >> n;
    city.resize(n);
    rep(i, n){
        int x, y;
        cin >> x >> y;
        city[i] = {x, y};
    }

    vector<int> ans;

    // 初期解
    vector<bool> ck(n, false);
    ck[0] = true;
    ans.push_back(0);
    auto now_idx = 0;
    while(ans.size() < n){
        int next_index;
        double min_dist = INF;
        rep(i, n){
            if(ck[i]) continue;
            double dist = distance(city[i], city[now_idx]);
            if(min_dist > dist){
                min_dist = dist;
                next_index = i;
            }
        }
        ans.push_back(next_index);
        now_idx = next_index;
        ck[next_index] = true;
    }
    
    //print("貪欲: " << 1000000 / culc_score(ans));
    
    std::mt19937 generator;
    generator.seed(std::random_device()());
    std::uniform_int_distribution<int> distribution(0, n-1);
    std::uniform_int_distribution<int> rnd(0, 32767);

    // 焼く
    double start_tmp = 15, end_tmp = 3;
    while(true){
        now = std::chrono::system_clock::now();
        double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now-start).count(); //処理に要した時間をミリ秒に変換
        if(elapsed > LMT) break;

        int a = distribution(generator);
        int b = distribution(generator);
        if(a == b || a == 0 || b == 0) continue;
        int pre_score = culc_diff_score(ans, a, b, n);
        swap(ans[a], ans[b]);
        int new_score = culc_diff_score(ans, a, b, n);

        double temp = start_tmp + (end_tmp - start_tmp) * (elapsed) / LMT;
        double prob = exp((pre_score-new_score)/temp);

        if(!(prob > (rnd(generator)%INF)/(double)INF)){
            swap(ans[a], ans[b]);
        }
    }
    ans.push_back(0);
    print_ans(ans);
    //print("END : " << 1000000 / culc_score(ans));
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
