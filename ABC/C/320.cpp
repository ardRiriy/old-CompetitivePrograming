#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
#define all(a) a.begin(), a.end()
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
using namespace std;
class UnionFind { 
    private: map<int, int> uf;
    public:
    int root(int n) { if (uf.find(n) == uf.end()) uf[n] = -1; if (uf[n] < 0) return n; else return uf[n] = root(uf[n]); }
    bool connected(int a, int b) { return root(a) == root(b); }
    void marge(int a, int b) { int root_a = root(a); int root_b = root(b); if (root_a != root_b) { if (uf[root_a] > uf[root_b]) swap(root_a, root_b); uf[root_a] += uf[root_b]; uf[root_b] = root_a; }}
    int size(int n) { return -uf[root(n)]; }
};
bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int x, int n) { int result = 1; while(n > 0){ if((n & 1) == 1){ result *= x; } x *= x; n >>= 1; } return result; } /*x^nを計算*/
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

void solve() {
    // hogehoge
    int m;
    cin >> m;
    map<char, vector<int>> m1, m2, m3;

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    rep(i, m){
        m1[s1[i]].push_back(i);
        m2[s2[i]].push_back(i);
        m3[s3[i]].push_back(i);
    }

    int ans = INF;

    for(char d = '0'; d <= '9'; ++d){
        for(int t1: m1[d]){
            for(int t2: m2[d]){
                for(int t3: m3[d]){
                    vector<int> times = {t1, t2, t3};
                    sort(times.begin(), times.end());

                    long long total_time = times[0];
                    for (int i = 1; i < 3; ++i) {
                        if (times[i] == times[i - 1]) {
                            total_time += m;
                        } else {
                            total_time = max(total_time, times[i]);
                        }
                    }

                    chmin(ans, total_time);
                }
            }
        }
    }
    if(ans != INF)print(ans);
    else print(-1);
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
