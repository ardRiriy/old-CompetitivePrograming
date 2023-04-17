#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;

    int a[n];

    LOOP(i, n) cin >> a[i];

    LOOP(i, n) {
        if (i + 1 >= p && i + 1 <= q) {
            cout << a[i + (r - p)] << " ";
        } else if (i + 1 >= r && i + 1 <= s) {
            cout << a[i - (r - p)] << " ";
        } else
            cout << a[i] << " ";
    }
    cout << endl;
}