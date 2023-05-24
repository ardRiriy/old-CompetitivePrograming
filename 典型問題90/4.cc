#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int h, w;
    cin >> h >>w;
    int a[h][w];

    rep(i, h) rep(j, w) cin >> a[i][j];

    int h_sum[w];
    int w_sum[h];

    rep(i, w){
        int sum = 0;
        rep(k, h) sum += a[k][i];
        h_sum[i] = sum;
    }

    rep(i, h){
        int sum = 0;
        rep(k, w) sum += a[i][k];
        w_sum[i] = sum;
    }

    rep(i, h){
        rep(k, w){
            cout << w_sum[i] + h_sum[k] - a[i][k] << " ";
        }
        cout << endl;
    } 
    return 0;
}

