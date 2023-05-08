#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int a, b, k;
    cin >> a >> b >> k;

    int ans = 0;
    while(a < b){
        ans++;
        a *= k;
    }
    cout << ans << endl;
    return 0;
}


