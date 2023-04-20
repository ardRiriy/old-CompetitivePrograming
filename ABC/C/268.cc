// 解説AC
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> cnt(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cnt[(p[i] - 1 - i + j + n) % n]++;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) ans = max(ans, cnt[i]);
    cout << ans << endl;
    return 0;
}