#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = 8;

    bool b_odd = false;
    bool b_even = false;

    bool k_pre = false;
    bool k_rear = false;

    bool ans = true;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            if (i % 2 == 0) {
                if (!b_even)
                    b_even = true;
                else {
                    ans = false;
                    break;
                }
            } else {
                if (!b_odd)
                    b_odd = true;
                else {
                    ans = false;
                    break;
                }
            }
        } else if (s[i] == 'K') {
            for (int j = 0; j < i; j++) {
                if (s[j] == 'R') k_pre = true;
            }
            for (int j = i; j < n; j++) {
                if (s[j] == 'R') k_rear = true;
            }

            if (!k_pre || !k_rear) {
                ans = false;
                break;
            }
        }
    }

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}