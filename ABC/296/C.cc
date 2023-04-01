#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    set<int> st;

    bool ans = false;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        st.insert(t);
    }

    for (auto itr = st.begin(); itr != st.end(); ++itr) {
        if (st.count(x + *itr) == 1) {
            ans = true;
            break;
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
