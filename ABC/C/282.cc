#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    bool now = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == 34)
            now = !now;
        else if (s[i] == ',' && !now)
            s[i] = '.';
    }
    cout << s << endl;
    return 0;
}