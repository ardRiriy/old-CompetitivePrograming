#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    string s, t;
    cin >> s >> t;

    long long l = 0, r = t.size();

    while (true) {
        int m = (l + r) / 2;
        if (abs(l - r) <= 1) {
            PRINT(l + 1)
            break;
        }

        if (equal(s.begin() + l, s.begin() + m, t.begin() + l, t.begin() + m)) {
            l = m;
        } else {
            r = m;
        }
    }
}
