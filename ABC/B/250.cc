#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int a, b, n;
    cin >> n >> a >> b;
    /* 0: startが白*/
    int stats = 0;
    rep(i, a*n){
        if(i % a == 0 && i != 0){
            if(stats == 0) stats = 1;
            else stats = 0;
        }
        int now = stats;
        rep(k, b*n){
            if(k % b== 0 && k != 0){
                if(now == 0) now = 1;
                else now = 0;
            }
            if(now == 0)cout << '.';
            else cout << "#";
        }
        cout << endl;
    }
    return 0;
}

