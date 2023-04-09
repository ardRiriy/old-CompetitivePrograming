#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    long long ans = 0;
    // reverse(s.begin(), s.end()); <- その反転，本当に必要でしたか？？？
    while (true) {
        if (s.size() == 0) break;
        if (s.size() == 1) {
            ans += 1;
            break;
        }
        if (s[0] == '0' && s[1] == '0') {
            s.erase(s.begin());
        }
        ans += 1;
        s.erase(s.begin());
    }

    cout << ans << endl;
    return 0;
}