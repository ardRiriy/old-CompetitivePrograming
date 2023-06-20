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

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<bool> vec(N + 2, false);
    stack<int> stk;
    vec[1] = true;
    int tmp;
    cin >> tmp;
    rep(i, tmp) {
        int q;
        cin >> q;
        vec[q] = true;
        stk.push(q);
    }

    while (!stk.empty()) {
        int p = stk.top();
        stk.pop();
        if (p == N) {
            cout << p << endl;
            string s;
            cin >> s;
            return 0;
        }
        cout << p << endl;
        int k;
        cin >> k;
        rep(i, k) {
            int q;
            cin >> q;
            if (!vec[q]) {
                vec[q] = true;
                stk.push(q);
            }
        }
    }

    return 0;
}
