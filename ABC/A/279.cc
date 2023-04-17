#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for (auto& c : s) {
        if (c == 'w')
            ans += 2;
        else
            ans++;
    }
    PRINT(ans)
    return 0;
}