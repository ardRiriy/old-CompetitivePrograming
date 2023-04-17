// これは遅い．もっと高速化するか別の手段を考えないといけない．

#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (long long i = 0; i < n; i++)

long long mod = 998244353;

long long mod_string_to_num(const string &s) {
    long long res = 0;
    for (char c : s) {
        res = (res * 10 + (c - '0')) % mod;
    }
    return res;
}

int main() {
    long long q;
    cin >> q;

    string s = "1";

    int e;
    LOOP(i, q) {
        cin >> e;
        if (e == 1) {
            char x;
            cin >> x;
            s.push_back(x);
        } else if (e == 2) {
            s.erase(s.begin());
        } else {
            PRINT(mod_string_to_num(s))
        }
    }

    return 0;
}
