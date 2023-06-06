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
    int N, D;
    cin >> N >> D;
    int v[N][2];

    rep(i, N) {
        cin >> v[i][0];
        cin >> v[i][1];
    }

    vector<bool> is(N, false);
    is[0] = true;

    queue<int> que;
    que.push(0);
    while (!que.empty()) {
        int i = que.front();
        rep(k, N) {
            if (i == k || is[k]) continue;
            int kyori =
                pow((v[i][0] - v[k][0]), 2) + pow((v[i][1] - v[k][1]), 2);
            if (kyori <= D * D) {
                is[k] = true;
                que.push(k);
            }
        }
        que.pop();
    }

    rep(i, N) {
        if (is[i]) YES else NO
    }
    return 0;
}
