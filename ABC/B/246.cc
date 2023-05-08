#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int a, b;
    cin >> a >> b;
    double d = sqrt(a * a + b * b);
    double x = a / d;
    double y = b / d;
    cout << x << " " << y << endl;
    return 0;
}
