#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, q;
    cin >> n >> q;

    set<int> st;
    int next = 1;
    vector<int> ans(q);
    int a_i = 0;
    LOOP(i, q) {
        int e;
        cin >> e;
        if (e == 1)
            st.insert(next++);
        else if (e == 2) {
            cin >> e;
            st.erase(e);
        } else
            ans[a_i++] = *st.begin();
    }
    LOOP(i, a_i) cout << ans[i] << endl;

    return 0;
}