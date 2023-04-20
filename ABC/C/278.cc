#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    map<int, set<int>> mp;

    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            mp[a].insert(b);
        } else if (t == 2) {
            mp[a].erase(b);
        } else {
            if (mp[a].count(b) == 1 && mp[b].count(a) == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}