#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = n; i > (int)(n); i--)
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
const int LMT = 2000; // ミリ秒指定

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
vector<vector<int>> ans(10000, vector<int>(4));

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
    }
    cout << endl;
}

void ball_swap(){

}

void solve() {
    // hogehoge
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now();
    vector<vector<int>> ball(N, vector<int>(N, INF));

    rep(i, N){
        rep(k, i+1){
            cin >> ball[i][k];
        }
    } 
    
    while(true){
        bool flag = true;
        rep(i, N){
            if(i==0) continue;
            rep(k, i+1){
                if(k == 0){
                    if(ball[i][k] < ball[i-1][k]){
                        swap(ball[i][k], ball[i-1][k]);
                        ans_writer(i, k, i-1, k);
                        flag = false;
                    }
                }else{
                    if(ball[i-1][k] == INF){
                        if(ball[i][k] < ball[i-1][k-1]){
                            swap(ball[i][k], ball[i-1][k-1]);
                            ans_writer(i, k, i-1, k-1);
                            flag = false;
                        }
                    }else{
                        if(ball[i-1][k] > ball[i-1][k-1]){
                            if(ball[i][k] < ball[i-1][k]){
                                swap(ball[i][k], ball[i-1][k]);
                                ans_writer(i, k, i-1, k);
                                flag = false;
                            }
                        }else{
                            if(ball[i][k] < ball[i-1][k-1]){
                                swap(ball[i][k], ball[i-1][k-1]);
                                ans_writer(i, k, i-1, k-1);
                                flag = false;
                            }
                        }
                    }
                }
            }
        } 
        if(flag) break;
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
