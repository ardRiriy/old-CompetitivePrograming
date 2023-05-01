#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<int> q;
    rep(i, n - 1) {
        if (s[i] == 'n' && s[i + 1] == 'a') {
            q.insert(i + 1);
        }
    }
    int c = 0;
    for (auto itr = q.begin(); itr != q.end(); itr++) {
        s.insert(s.begin() + *itr + c, 'y');
        c++;
    }

    cout << s << endl;
    return 0;
}