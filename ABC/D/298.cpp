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

int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }


int MOD = 998244353;
int power(int x, int n) {
    int result = 1;
    while(n > 0){
        if((n & 1) == 1){
            result *= x;
            result %= MOD;
        }
        x *= x;
        n >>= 1;
    }
    return result; 
}

void solve() {
    // hogehoge
    int Q;
    cin >> Q;
    deque<int> que(1, 1);
    int ans = 1;

    while(Q--){
        int q;
        cin >> q;
        if(q == 1){
            cin >> q;
            que.push_back(q);
            ans = ans*10 + q;
            ans %= MOD;
        }else if(q == 2){
        if(q==2){
            int size=que.size();
            ans-=que.front()*power(10,size-1);
            ans+=MOD; 
            ans%=MOD;
            que.pop_front();
        }
        }else{
            print(ans);
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
