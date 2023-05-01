#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    int one = -1, two = 0;
    int one_i = -1, two_i = -1;
    rep(i, n) {
        int a;
        cin >> a;
        if (a > one) {
            two = one;
            one = a;
            two_i = one_i;
            one_i = i;
        } else if (a > two) {
            two = a;
            two_i = i;
        }
    }

    cout << two_i + 1 << endl;

    return 0;
}