#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;

    vector<vector<int>> vec(n);

    rep(i, n) {
        int l;
        cin >> l;
        rep(j, l) {
            int k;
            cin >> k;
            vec[i].push_back(k);
        }
    }

    set<vector<int>> st;

    rep(i, n) st.insert(vec[i]);

    cout << st.size() << endl;

    return 0;
}