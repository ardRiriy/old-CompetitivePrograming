#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);

    LOOP(i, n) cin >> vec[i];

    cout << vec[0] << " ";

    for (int i = 1; i < n; i++) cout << vec[i] - vec[i - 1] << " ";
    cout << endl;
}
