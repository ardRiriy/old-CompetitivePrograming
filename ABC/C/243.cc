#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(2));
    map<int, int> left;
    map<int, int> right;

    rep(i, n) {
        cin >> vec[i][0];
        cin >> vec[i][1];
    }

    string s;
    cin >> s;

    rep(i, n) {
        if (s[i] == 'L') {
            if (left.count(vec[i][1])) {
                if (left[vec[i][1]] < vec[i][0]) left[vec[i][1]] = vec[i][0];
            } else {
                left[vec[i][1]] = vec[i][0];
            }
        } else {
            if (right.count(vec[i][1])) {
                if (right[vec[i][1]] > vec[i][0]) right[vec[i][1]] = vec[i][0];
            } else {
                right[vec[i][1]] = vec[i][0];
            }
        }
    }

    for (auto itr = left.begin(); itr != left.end(); itr++) {
        if (!right.count(itr->first)) continue;
        if (itr->second > right[itr->first]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}