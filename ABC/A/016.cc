#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int m, d;
    cin >> m >> d;

    if (m % d == 0)
        PRINT("YES")
    else
        PRINT("NO")

    return 0;
}