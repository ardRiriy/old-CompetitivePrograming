#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, s, t;
    cin >> n >> s >> t;

    int a[n];
    int k;
    cin >> a[0];
    LOOP(i, n) {
        if (i == 0) continue;
        cin >> k;
        a[i] = a[i - 1] + k;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (s <= a[i] && a[i] <= t) ans++;

    PRINT(ans)
}