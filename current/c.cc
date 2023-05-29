#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int n, m, h, k;
    cin >> n >> m >> h >> k;

    string s;
    cin >> s;

    set<pair<int, int>> item;

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        auto p = make_pair(x, y);
        item.insert(p);
    }
    int cx = 0, cy = 0;
    rep(i, s.size()) {
        h--;
        if (h < 0) {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] == 'R')
            cx++;
        else if (s[i] == 'L')
            cx--;
        else if (s[i] == 'U')
            cy++;
        else
            cy--;

        auto now = make_pair(cx, cy);
        if (item.count(now) == 1 && h < k) {
            item.erase(now);
            h = k;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
