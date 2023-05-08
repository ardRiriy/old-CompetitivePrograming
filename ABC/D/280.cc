#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

// なんか動かない なんで？

signed main() {
    int k, p, a, n, x, ans = 1;
    cin >> k;
    for(p=2;(p*p) <= k; p++){
        a = 0;
        while(k % p == 0) k /= p, a++;
        n = 0;
        while(a > 0){
           n += p;
           x = n;
           while(x % p == 0) x/= p, a--;
        }
    }
    ans = max(ans, k);
    cout << ans << endl;
    return 0;
}
