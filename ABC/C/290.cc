#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1e9;

using namespace std;
bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    set<int> st;
    int N, K;
    cin >> N >> K;
    rep(i, N) {
        int tmp;
        cin >> tmp;
        st.insert(tmp);
    }

    rep(i, K) {
        if (st.count(i) == 0) {
            if (i == 0)
                cout << 0 << endl;
            else
                cout << i << endl;
            return 0;
        }
    }
    cout << K << endl;
    return 0;
}
