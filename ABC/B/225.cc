#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    map<int, int> m;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b;
        m[a]++;
        m[b]++;
    }

    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second == n - 1) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}