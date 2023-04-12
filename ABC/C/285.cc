// 3case WA
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    long long ans = 0;
    map<char, int> mp;

    int j = 1;
    for (char c = 'A'; c < 'A' + 26; c++) {
        mp[c] = j;
        j++;
    }

    for (long i = 0;; i++) {
        ans += pow(long(26), i) * mp[s.back()];
        s.pop_back();
        if (s.empty()) {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}