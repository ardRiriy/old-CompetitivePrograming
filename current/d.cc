#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;
bool chmin(int& a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

bool chmax(int& a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int b_search(vector<int>& v, int k) {
    int left = -1, right = v.size();
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

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> a_slp(N);
    a_slp[0] = 0;
    for (int i = 1; i < N; i++) {
        if (i % 2 == 0)
            a_slp[i] = a_slp[i - 1] + (A[i] - A[i - 1]);
        else
            a_slp[i] = a_slp[i - 1];
    }
    // for (int i : a_slp) cout << i << endl;
    int Q;
    cin >> Q;
    rep(i, Q) {
        int l, r;
        cin >> l >> r;
        int idx_l = b_search(A, l);
        int idx_r = b_search(A, r);
        // cout << idx_l << " " << idx_r << endl;
        int ans = a_slp[idx_r] - a_slp[idx_l];

        if (idx_l % 2 == 0) {
            ans += A[idx_l] - l;
        }

        if (idx_r % 2 == 0) {
            ans -= A[idx_r] - r;
        }
        cout << ans << endl;
    }
    return 0;
}
