#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    string s[h];

    for (int i = 0; i < h; i++) cin >> s[i];

    for (int i = 0; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (s[i][j - 1] == 'T' && s[i][j] == 'T') {
                s[i][j - 1] = 'P';
                s[i][j] = 'C';
            }
        }
        cout << s[i] << endl;
    }
    return 0;
}