#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    string s[r];

    for (int i = 0; i < r; i++) cin >> s[i];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!(s[i][j] == '.' || s[i][j] == '#')) {
                int bomb = s[i][j] - 48;
                s[i][j] = '.';
                for (int s1 = 0; s1 < r; s1++) {
                    for (int t = 0; t < c; t++) {
                        if (s[s1][t] == '#' &&
                            abs(i - s1) + abs(j - t) <= bomb) {
                            s[s1][t] = '.';
                        }
                    }
                }
            }
#
        }
    }

    for (int i = 0; i < r; i++) cout << s[i] << endl;
    return 0;
}
