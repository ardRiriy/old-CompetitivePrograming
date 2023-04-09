#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    int ng = -1;
    int ok = a.size();

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (a[mid] >= k)
            ok = mid;
        else
            ng = mid;
    }

    if (0 <= ok && ok < a.size())
        cout << ok << endl;
    else
        cout << -1 << endl;

    return 0;
}