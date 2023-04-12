// 言われたらわかるけどこれ解いて！て言われて解けるかというとだいぶあやしい
// 無理ポ...
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    set<long long> st;
    st.insert(0);
    long long ans;
    k++;
    while (k--) {
        ans = *st.begin();
        st.erase(st.begin());

        for (int i = 0; i < n; i++) {
            st.insert(ans + a[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
