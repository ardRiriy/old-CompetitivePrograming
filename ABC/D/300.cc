#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

#define MAXP 300005

vector<int> sieve() {
    vector<int> res;
    vector<int> mem(MAXP, 0);
    for (int i = 2; i < MAXP; i++) {
        if (mem[i]) continue;
        res.push_back(i);

        // 素数iの倍数はすべて合成数なので1で埋めて判定済みにする
        for (int j = i; j < MAXP; j += i) mem[j] = 1;
    }

    return res;
}

signed main() {
    vector<int> p = sieve();
    int n;
    cin >> n;

    int sz = p.size();
    int ans = 0;

    rep(i, sz) {
        int k = sz - 1;
        for (int j = i + 1; j < k && j < sz; j++) {
            while (j < k) {
                long long v = p[i] * p[i] * p[j];
                if (v > n) {
                    k--;
                    continue;
                }
                v *= p[k];
                if (v > n) {
                    k--;
                    continue;
                }
                v *= p[k];
                if (v > n) {
                    k--;
                    continue;
                }
                break;
            }
            ans += (k - j);
        }
    }

    cout << ans << endl;
    return 0;
}