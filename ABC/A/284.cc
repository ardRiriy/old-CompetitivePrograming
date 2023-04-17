#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    LOOP(i, n) cin >> s[i];
    LOOP(i, n) PRINT(s[n - 1 - i]);
}