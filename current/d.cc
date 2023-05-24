#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int b_search(vector<int> &v, int k){
    int left = -1, right = v.size();
    if(v.back() < k) return v.size() - 1;
    while(abs(right-left) > 1){
        int mid = (left + right) / 2;
        if(v[mid] >= k){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}


signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n);
    vector<int> b(m);

    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(a.begin(), a.end());
    int ans = 0;

    rep(i, m){
        int index = b_search(a, b[i]+d);
        if(b[i] + d  < a[index])index--;
        if(index >= 0 && a[index] >= b[i] - d) ans = max(ans, a[index] + b[i]);
    }
    
    if(ans == 0) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
