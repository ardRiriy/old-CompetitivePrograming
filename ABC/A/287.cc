#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    int ag = 0;

    LOOP(i, n) {
        string s;
        cin >> s;
        if (s == "Against") ag++;
    }

    if (ag >= n / 2 + 1)
        PRINT("No")
    else
        PRINT("Yes")
    return 0;
}