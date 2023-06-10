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
    char q, p;
    cin >> p >> q;
    map<char, int> m;
    m['A'] = 0;
    m['B'] = 3;
    m['C'] = 4;
    m['D'] = 8;
    m['E'] = 9;
    m['F'] = 14;
    m['G'] = 23;

    cout << abs(m[p] - m[q]) << endl;
    return 0;
}
