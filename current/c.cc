#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;

using namespace std;
bool chmin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

bool chmax(int &a, int b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    int N;
    cin >> N;
    map<int, int> mp;
    set<pair<int, int>> st;
    rep(i, 3 * N) {
        int x;
        cin >> x;
        mp[x]++;
        if (mp[x] == 2) {
            auto p = make_pair(i, x);
            st.insert(p);
        }
    }
    for (auto itr = st.begin(); itr != st.end(); itr++) {
        cout << itr->second << " ";
    }
    cout << endl;
    return 0;
}
