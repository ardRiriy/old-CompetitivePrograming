#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int n1 = ceil(25.0 * (float)a / 2.0);
    int n2 = 10 * b;

    int ans = -1;

    if (b == n1 / 10) {
        ans = n1;
    } else if (a == n2 * 2 / 25) {
        ans = n2;
    }
    cout << ans << endl;
    return 0;
}