#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    string s;
    cin >> n >> s;
    bool a = true;
    bool sub = false;
    LOOP(i, n) {
        if (s[i] == 'o')
            sub = true;
        else if (s[i] == 'x')
            a = false;
    }

    if (a && sub)
        cout << "Yes" << endl;
    else
        PRINT("No")
    return 0;
}