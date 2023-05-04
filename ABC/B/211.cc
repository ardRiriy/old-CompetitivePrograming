#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    string s;
    set<string> st;
    rep(i, 4) {
        cin >> s;
        st.insert(s);
    }
    if (st.size() == 4)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}