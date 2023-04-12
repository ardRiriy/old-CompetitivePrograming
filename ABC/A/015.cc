#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() > b.size())
        PRINT(a)
    else
        PRINT(b)

    return 0;
}