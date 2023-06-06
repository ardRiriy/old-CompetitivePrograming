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
    cin >> N;
    if (N < 10 * 10 * 10) {
    } else if (N < 10 * 10 * 10 * 10) {
        N /= 10;
        N *= 10;
    } else if (N < 10 * 10 * 10 * 10 * 10) {
        N /= 100;
        N *= 100;
    } else if (N < 10 * 10 * 10 * 10 * 10 * 10) {
        N /= 1000;
        N *= 1000;
    } else if (N < 10 * 10 * 10 * 10 * 10 * 10 * 10) {
        N /= 10000;
        N *= 10000;
    } else if (N < 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10) {
        N /= 100000;
        N *= 100000;
    } else {
        N /= 1000000;
        N *= 1000000;
    }
    cout << N << endl;
    return 0;
}
