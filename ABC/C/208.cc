#include <bits/stdc++.h>

using namespace std;

int main() {
    long n, k;
    cin >> n >> k;
    long all = 0;
    if (n <= k) {
        all = k / n;
        k = k % n;
    }
    vector<int> vec(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        st.insert(vec[i]);
    }
    auto itr = st.begin();
    for (int i = 0; i < k; i++) {
        itr++;
    }
    st.erase(itr, st.end());

    for (int i = 0; i < n; i++) {
        if (st.count(vec[i]) == 0) {
            cout << all << endl;
        } else {
            cout << all + 1 << endl;
        }
    }

    return 0;
}