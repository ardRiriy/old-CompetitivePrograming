#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> v(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> v[i][j];

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (v[i][j] == 0)
                cout << ".";
            else
                cout << char(v[i][j] + 64);
        }
        cout << endl;
    }
    cout << endl;
    return 0;
};