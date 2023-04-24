#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    int l = 1;
    int r = n;

    int mid;
    int midn;

    rep(i, 20) {
        if (abs(l - r) <= 1) break;
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        cin >> midn;
        if (midn == 0) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << "! " << l << endl;

    return 0;
}