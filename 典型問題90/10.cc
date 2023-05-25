#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int n, q;
    cin >> n;

    int sum1[n + 1];
    int sum2[n + 1];
    int t1 = 0, t2 = 0;
    sum1[0] = 0;
    sum2[0] = 0;
    rep(i, n) {
        int c, p;
        cin >> c >> p;
        if (c == 1)
            t1 += p;
        else
            t2 += p;

        sum1[i + 1] = t1;
        sum2[i + 1] = t2;
    }

    cin >> q;

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << sum1[r] - sum1[l - 1] << " " << sum2[r] - sum2[l - 1] << endl;
    }
    return 0;
}
