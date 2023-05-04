#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int a, b;
    cin >> a >> b;
    cout << fixed << std::setprecision(0);
    cout << pow(32, a - b) << endl;
    return 0;
}