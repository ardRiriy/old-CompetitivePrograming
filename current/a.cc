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
    int n;
    cin >> n;
    string s[n];
    int age[n];

    rep(i, n) {
        cin >> s[i];
        cin >> age[i];
    }
    int min = INF;
    int l;
    rep(i, n) {
        if (chmin(min, age[i])) l = i;
    }

    rep(i, n) { cout << s[(l + i) % n] << endl; }
    return 0;
}
