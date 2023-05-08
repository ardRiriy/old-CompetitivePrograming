#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int h , w;
    cin >> h >> w;
    int a[h][w];
    rep(i, h)rep(k, w) cin >> a[i][k];
    
    rep(i, h){
        rep(k, w){
            for(int x = i; x < h; x++){
                for(int y = k;y < w;y++){
                    if(x == i || y == k) continue;
                    if(a[i][k] + a[x][y] > a[x][k] + a[i][y]){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes"<<endl;

    return 0;
}
