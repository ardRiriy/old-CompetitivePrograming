#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 1; i < (int)(n); i++)
#define rep2(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int k = c * d - b;
    if (k <= 0) {
        cout << "-1" << endl;

    } else {
        int water = a, red = 0;
        int ans = 0;
        while (true) {
            if (water <= red * d) {
                cout << ans << endl;
                return 0;
            } else {
                water += b;
                red += c;
                ans++;
            }
        }
    }

    return 0;
}