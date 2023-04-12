#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;

int adder(int x) {
    if (x == 1)
        return 1;
    else
        return adder(x - 1) + x;
}

int main() {
    int n;
    cin >> n;
    PRINT(adder(n) * 10000 / n);
    return 0;
}