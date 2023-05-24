#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int b_search(vector<int> &v, int k) {
    int left = -1, right = v.size();
    if (v.back() < k) return -1;
    while (abs(right - left) > 1) {
        int mid = (left + right) / 2;
        if (v[mid] >= k) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    cin >> q;
    rep(i, q) {
        int b;
        cin >> b;
        int idx = b_search(a, b);
        if (idx == -1)
            cout << abs(b - a.back()) << endl;
        else if (idx == 0)
            cout << abs(a[0] - b) << endl;
        else
            cout << min(abs(a[idx] - b), abs(a[idx - 1] - b)) << endl;
    }
    return 0;
}
