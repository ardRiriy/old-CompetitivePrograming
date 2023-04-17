#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int h, w;
    cin >> h >> w;
    string s[h];

    LOOP(i, h) cin >> s[i];

    int ans = 0;

    LOOP(i, h) LOOP(j, w) {
        if (s[i][j] == '#') ans++;
    }

    PRINT(ans);

    return 0;
}
