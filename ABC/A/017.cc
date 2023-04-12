#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int a[3][2];

    LOOP(i, 3) LOOP(j, 2) cin >> a[i][j];

    int ans = 0;

    LOOP(i, 3) ans += a[i][0] * a[i][1] / 10;

    PRINT(ans)
    return 0;
}