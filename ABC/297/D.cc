#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long ans = 0;

    if (a < b) swap(a, b);
    while (b > 0) {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    cout << ans - 1 << endl;
}