#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    rep(i, n) {
        int a;
        cin >> a;
        if ((i + 1) % 2 == 0) {
            sum += (a - 1);
        } else {
            sum += a;
        }
    }

    if (sum <= x)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}