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
    int N;
    string S;
    cin >> N >> S;
    rep(i, N) cout << S[i] << S[i];
    cout << endl;
    return 0;
}
