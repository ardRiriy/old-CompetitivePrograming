#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;

    LOOP(i, n) cout << char('A' + i);
    cout << endl;
    return 0;
}