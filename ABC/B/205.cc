#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    bool a[n + 1];

    rep(i, n) {
        int k;
        cin >> k;
        if (k > n) continue;
        a[k] = true;
    }

    bool ans = true;
    rep(i, n) {
        if (!a[i + 1]) {
            ans = !ans;
            break;
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}