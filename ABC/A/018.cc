#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    if (a > b && a > c) {
        cout << 1 << endl;
        if (b > c)
            cout << 2 << endl << 3 << endl;
        else
            cout << 3 << endl << 2 << endl;
    } else if (b > a && b > c) {
        if (a > c)
            cout << 2 << endl << 1 << endl << 3 << endl;
        else
            cout << 3 << endl << 1 << endl << 2 << endl;
    } else {
        if (a > b)
            cout << 2 << endl << 3 << endl;
        else
            cout << 3 << endl << 2 << endl;
        cout << 1 << endl;
    }
    return 0;
}