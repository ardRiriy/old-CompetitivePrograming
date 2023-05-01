
#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    map<string, int> m;
    rep(i, n) {
        string s;
        cin >> s;
        m[s]++;
    }

    int max = -1;
    string mxName;
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second > max) {
            max = itr->second;
            mxName = itr->first;
        }
    }

    cout << mxName << endl;
    return 0;
}