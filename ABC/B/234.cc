#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int n;
    cin >> n;
    int a[n][2];
    rep(i, n){
        cin >> a[i][0];
        cin >> a[i][1];
    }

    int ma = 0;
    rep(i, n){
        for(int j = i; j < n; j++){
            if(i == j) continue;
            int d = pow(a[i][0] - a[j][0], 2) + pow(a[i][1] - a[j][1], 2);
            ma = max(ma, d);
        }
    }

    double ans = sqrt(ma); 
    cout << std::setprecision(20) << ans << endl;
    return 0;
}

