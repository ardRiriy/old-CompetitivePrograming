#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (k % 2 == 0) v[i] = k;
    }

    for (int i = 0; i < n; i++) {
        if (v[i] == 0)
            continue;
        else
            cout << v[i] << " " << endl;
    }
    cout << endl;
    return 0;
}
