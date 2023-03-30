// たかし，これで喜んでくれ
#include <bits/stdc++.h>

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;

    int vec[w][h];

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            cin >> vec[x][y];
        }
    }

    int l = h + w - 2;
    int p[l];
    for (int i = 0; i < l; i++) {
        if (i > w - 2)
            p[i] = 1;
        else
            p[i] = 0;
    }
    int ans = 0;
    do {
        set<int> st;
        st.insert(vec[0][0]);
        int x = 0;
        int y = 0;
        for (int i = 0; i < l; i++) {
            if (p[i] == 0)
                x += 1;
            else
                y += 1;
            st.insert(vec[x][y]);
        }
        if (st.size() == l + 1) ans++;
    } while (next_permutation(p, p + l));

    cout << ans << endl;
    return 0;
}