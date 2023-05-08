#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    map<int, int> a;
    vector<int> b(m);

    rep(i, n) {
        int k;
        cin >> k;
        a[k]++;
    }
    rep(i, m) cin >> b[i];

    rep(i, m) {
        if (a[b[i]] == 0) {
            cout << "No" << endl;
            return 0;
        } else {
            a[b[i]]--;
        }
    }
    cout << "Yes" << endl;
    return 0;
}