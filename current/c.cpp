#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
using namespace std;

void solve() {
    // hogehoge
    int n, d, p;
    cin >> n >> d >> p;
    vector<int> f(n);
    rep(i, n) cin >> f[i];
    sort(f.rbegin(), f.rend());
    int ans = 0;
    vector<int> f_sum(n+1);
    f_sum[0] = 0;
    rep(i, n){
        f_sum[i+1] = f_sum[i] + f[i];
    }
    // for(int i: f_sum) print(i);

    rep(i, n){
    //print(i << " " << ans << " " << f_sum[min(i+d, n)]  << " " << f_sum[i]);
    
        if(f_sum[min(i+d, n)] - f_sum[i] >= p) {
            ans += p;
            i+=(d-1);
        }else{
            ans += f[i];
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
