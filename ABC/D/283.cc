// これは嘘解放らしい

#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    string s;
    cin >> s;
    bool ans = true;

    set<char> jg;

    LOOP(i, s.size()) {
        if (s[i] == ')')
            jg.clear();
        else if (s[i] != '(') {
            if (jg.count(s[i]) == 1) {
                ans = false;
                break;
            } else
                jg.insert(s[i]);
        }
    }

    if (ans)
        PRINT("Yes")
    else
        PRINT("No")

    return 0;
}
