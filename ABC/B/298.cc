#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a((n), vector<int>(n));
    vector<vector<int>> b((n), vector<int>(n));
    vector<vector<int>> t((n), vector<int>(n));
    vector<vector<int>> p((n), vector<int>(n));
    vector<vector<int>> w((n), vector<int>(n));

    LOOP(i, n) LOOP(j, n) {
        cin >> a[i][j];
        p[n - 1 - j][i] = a[i][j];
        t[n - 1 - i][n - 1 - j] = a[i][j];
        w[j][n - 1 - i] = a[i][j];
    }
    LOOP(i, n) LOOP(j, n) cin >> b[i][j];

    bool a1 = true, a2 = true, a3 = true, a4 = true;

    LOOP(i, n) LOOP(j, n) {
        if (a[i][j] == 1 && a1)
            if (b[i][j] != 1) {
                a1 = false;
            }
        if (t[i][j] == 1 && a2)
            if (b[i][j] != 1) {
                a2 = false;
            }
        if (p[i][j] == 1 && a3)
            if (b[i][j] != 1) {
                a3 = false;
            }
        if (w[i][j] == 1 && a4)
            if (b[i][j] != 1) {
                a4 = false;
            }
    }

    if (a1 || a2 || a3 || a4)
        PRINT("Yes")
    else
        PRINT("No");
    return 0;
}