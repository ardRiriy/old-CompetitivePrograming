#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
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
void solve() {
    // hogehoge
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N, 0);
    multiset<int> ms;
    int now_sum = 0;
    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--;

        int tmp = A[x];
        A[x] = y;
        if (ms.count(tmp) != 0) {
            ms.erase(tmp);
        }
        ms.insert(y);
        while (ms.size() > K) {
            ms.erase(ms.begin());
        }

        now_sum += (y - tmp);
        cout << now_sum << endl;
    }
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int times = 1;
    // cin >> times;
    while (times--) solve();
    return 0;
}
