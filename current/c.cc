#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char, int> mp;
    rep(i, n) mp[s[i]]++;  // O(n)
    cout << mp['R'] << " " << mp['G'] << " " << mp['B'] << endl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            for (int j = i; j < n; j++) {
                if (s[j] == 'G') {
                    int k = 2 * j - i;
                    cout << i << j << k - 1 << endl;

                    if (k < n) {
                        if (s[k - 1] != 'B') {
                            ans += mp['B'];
                        } else {
                            ans += mp['B'] - 1;
                        }
                    }
                } else if (s[j] == 'B') {
                    int k = 2 * j - i;
                    cout << i << j << k - 1 << endl;

                    if (k < n) {
                        if (s[k - 1] != 'G') {
                            ans += mp['G'];
                        } else {
                            ans += mp['G'] - 1;
                        }
                    }
                }
            }
        } else if (s[i] == 'G') {
            for (int j = i; j < n; j++) {
                if (s[j] == 'R') {
                    int k = 2 * j - i;
                    cout << i << j << k - 1 << endl;

                    if (k < n) {
                        if (s[k - 1] != 'B') {
                            ans += mp['B'];
                        } else {
                            ans += mp['B'] - 1;
                        }
                    }
                } else if (s[j] == 'B') {
                    int k = 2 * j - i;
                    cout << i << j << k - 1 << endl;

                    if (k < n) {
                        if (s[k - 1] != 'R') {
                            ans += mp['R'];
                        } else {
                            ans += mp['R'] - 1;
                        }
                    }
                }
            }
        } else {  // B
            for (int j = i; j < n; j++) {
                if (s[j] == 'G') {
                    int k = 2 * j - i;
                    cout << i << j << k - 1 << endl;

                    if (k < n) {
                        if (s[k - 1] != 'R') {
                            ans += mp['R'];
                        } else {
                            ans += mp['R'] - 1;
                        }
                    }
                } else if (s[j] == 'R') {
                    int k = 2 * j - i;
                    if (k < n) {
                        if (s[k - 1] != 'G') {
                            ans += mp['G'];
                        } else {
                            ans += mp['G'] - 1;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}