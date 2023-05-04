#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int, int> m;
    rep(i, n) {
        cin >> a[i];
        m[a[i]]++;
    }
    rep(i, n) {
        cin >> b[i];
        m[b[i]]++;
    }
    int ansA = 0, ansB = 0;
    rep(i, n) {
        // cout << "a[i]:" << a[i] << endl;
        if (a[i] == b[i])
            ansA++;
        else if (m[a[i]] == 2)
            ansB++;
        // cout << "A: " << ansA << endl;
        // cout << "B: " << ansB << endl;
    }
    cout << ansA << endl << ansB << endl;
    return 0;
}