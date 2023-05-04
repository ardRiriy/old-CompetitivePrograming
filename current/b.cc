#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n, k;
    int ans = 0;

    cin >> n >> k;
    set<int> st;
    map<int, int> cnt;
    vector<int> c(k, -1);
    rep(i, n) {
        int last = c[i % k];
        cin >> c[i % k];

        cnt[c[i % k]]++;
        if (i >= k) {
            cnt[last]--;
            if (cnt[last] == 0) {
                st.erase(last);
            }
        }
        st.insert(c[i % k]);
        if (ans < st.size()) ans = st.size();
    }

    cout << ans << endl;

    return 0;
}