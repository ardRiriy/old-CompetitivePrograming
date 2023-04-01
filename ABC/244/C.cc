#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    n = 2 * n + 1;
    int in;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }

    while (true) {
        cout << *st.begin() << endl;

        st.erase(st.begin());
        cin >> in;
        if (in == 0)
            break;
        else
            st.erase(in);
    }

    return 0;
}