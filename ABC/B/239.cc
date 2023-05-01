#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    int k = n / 10;
    if (n > 0 || n % 10 == 0)
        cout << k << endl;
    else
        cout << k - 1 << endl;
    return 0;
}