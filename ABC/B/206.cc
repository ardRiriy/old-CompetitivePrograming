#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    int sum = 0;
    rep(i, 1000000000) {
        sum += (i + 1);
        if (sum >= n) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}