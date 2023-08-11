#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define print(x) cout << x << endl
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
int power(int base, int exponent) {int result = 1;for (int i = 0; i < exponent; i++) result *= base; return result; }
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

map<int, int> mp;
map<int, bool> ck;

void init(){
    //int n = 1000008;
    int n = 300005;
    for(int i = 2; i < n; i++){
        if(ck[i]) continue;
        else{
            mp[i] = power(i, 2);
            for(int j = i; j < n; j += i){
                ck[j] = true;
            }
        }
    }
}

void solve() {
    // hogehoge
    int n;
    cin >> n;
    int ans = 0;
    init();
    itrep(itr1, mp){
        if(itr1->first * itr1->second * itr1->second > n) break;
        for(auto itr2 = itr1; itr2 != mp.end(); itr2++){
            if(itr2->first * itr1->second * itr2->second > n) break;
            if(itr2 == itr1) continue;
            int k = itr1->second * itr2->first;
            if(k > n) break;
            for(auto itr3 = itr2; itr3 != mp.end(); itr3++){
                if(itr2 == itr3) continue;
                if(k * itr3->second <= n) ans++;
                else break;
            }
        }
    }
    print(ans);
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
