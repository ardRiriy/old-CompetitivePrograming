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

    unordered_map<int, vector<int>> ladder;
    rep(i, N) {
        int a, b;
        cin >> a >> b;
        ladder[a].push_back(b);
        ladder[b].push_back(a);
    }

    queue<int> st;
    st.push(1);
    map<int, bool> ck;
    int max = N_INF;
    while (!st.empty()) {
        int f = st.front();
        for (int i : ladder[f]) {
            if (!ck[i]) st.push(i);
            ck[i] = true;
        }
        chmax(max, f);
        st.pop();
    }

    cout << max << endl;
    return 0;
}
