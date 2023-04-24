#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    string s;
    cin >> n >> s;

    int ans = -1;
    rep(i, n) {
        if (s[i] == 'o') {
            int j = 1;
            while (true) {
                if (i + j == n) break;
                if (s[i + j] == '-') {
                    if (ans < j) ans = j;
                    break;
                }
                j++;
            }
            i += j;
        }
    }

    reverse(s.begin(), s.end());

    rep(i, n) {
        if (s[i] == 'o') {
            int j = 1;
            while (true) {
                if (i + j == n) break;
                if (s[i + j] == '-') {
                    if (ans < j) ans = j;
                    break;
                }
                j++;
            }
            i += j;
        }
    }

    cout << ans << endl;

    return 0;
}