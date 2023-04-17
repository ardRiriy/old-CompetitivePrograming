#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int a, b;
    cin >> a >> b;

    if (a * 2 == b || a * 2 + 1 == b)
        PRINT("Yes")
    else
        PRINT("No")
    return 0;
}