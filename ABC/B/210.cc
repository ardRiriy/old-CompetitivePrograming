#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (i % 2 == 0)
                cout << "Takahashi" << endl;
            else
                cout << "Aoki" << endl;
            return 0;
        }
    }
    return 0;
}