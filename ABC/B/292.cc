#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n, q;
    cin >> n >> q;
    int e;
    set<int> y;
    set<int> r;
    while (q--) {
        int e, x;
        cin >> e >> x;

        if (e == 1) {
            if (y.count(x) == 1) {
                r.insert(x);
            } else {
                y.insert(x);
            }
        } else if (e == 2) {
            r.insert(x);
        } else {
            if (r.count(x) == 1) {
                PRINT("Yes")
            } else {
                PRINT("No")
            }
        }
    }

    return 0;
}