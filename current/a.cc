#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    
    int a, b;
    
    cin >> a >> b;
    int ans = a/b;
    if(a%b == 0) cout << ans << endl;
    else cout << ans + 1 << endl;

    return 0;
}

