#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);

    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    rep(i, n) ans += abs(a[i] - b[i]);
    cout << ans << endl;
    return 0;
}
