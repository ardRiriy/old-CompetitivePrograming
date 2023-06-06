#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;
bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

bool chmax(int &a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int n, l;
    int k;
    cin >> n >> l >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    auto ck = [&](int x) -> bool {
        int num = 0;
        int pre = 0;
        rep(i, n) {
            if (a[i] - pre >= x) {
                num++;
                pre = a[i];
            }
        }
        if (l - pre >= x) num++;
        return (num >= k + 1);
    };

    int left = -1, r = l + 1;
    while (abs(left - r) > 1) {
        int mid = (left + r) / 2;
        if (ck(mid)) {
            left = mid;
        } else {
            r = mid;
        }
    }
    cout << left << endl;
    return 0;
}
