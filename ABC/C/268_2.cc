// 解説読んだ後の実装し直し
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // mapで処理したほうが早いかなぁと思ったけどそうでもないらしい
    map<int, int> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            c[(i - p[i] + (j - 1) + n) % n]++;
        }
    }

    int m = 0;
    for (int i = 0; i < n; i++) m = max(m, c[i]);
    cout << m << endl;

    return 0;
}