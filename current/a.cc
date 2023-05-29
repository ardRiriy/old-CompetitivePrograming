#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int n;
    string s, t;
    cin >> n >> s >> t;

    rep(i, n) {
        if (s[i] != t[i]) {
            if (!((s[i] == 'l' && t[i] == '1') ||
                  (s[i] == '1' && t[i] == 'l'))) {
                if (!((s[i] == '0' && t[i] == 'o') ||
                      (s[i] == 'o' && t[i] == '0'))) {
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
