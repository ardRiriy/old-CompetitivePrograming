#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    string s;
    cin >> s;
    for (auto& c : s) {
        if (islower(c)) c = toupper(c);
    }

    cout << s << endl;
    return 0;
}