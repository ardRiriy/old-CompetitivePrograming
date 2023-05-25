#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 10000;
    rep(i, 10000) {
        rep(j, 10000) {
            int t = i * a + j * b;
            if (t > n) break;
            if ((n - t) % c == 0)
                ans = min(ans, i + j + (n - t) / c);
            else
                continue;
        }
    }
    cout << ans << endl;
    return 0;
}
