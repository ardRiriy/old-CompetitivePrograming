#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    string s;
    string min =
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
        "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    string max = "";
    set<string> st;
    cin >> s;
    rep(i, s.size()) {
        char l = s[0];
        for (int j = 0; j < s.size() - 1; j++) s[j] = s[j + 1];
        s[s.size() - 1] = l;
        if (min > s) min = s;
        if (max < s) max = s;
    }
    cout << min << endl << max << endl;

    return 0;
}