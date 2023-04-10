#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> vec(h, vector<char>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) cin >> vec[i][j];

    int x = 0, y = 0;
    set<int> st;
    while (true) {
        if (st.count(x + y * w) == 1) {
            cout << -1 << endl;
            break;
        } else {
            st.insert(x + y * w);
        }
        if (vec[x][y] == 'U' && x != 0)
            x--;
        else if (vec[x][y] == 'D' && x != h - 1)
            x++;
        else if (vec[x][y] == 'L' && y != 0)
            y--;
        else if (vec[x][y] == 'R' && y != w - 1)
            y++;
        else {
            cout << x + 1 << " " << y + 1 << endl;
            break;
        }
    }
    return 0;
}