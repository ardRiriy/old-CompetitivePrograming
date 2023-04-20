#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.begin(), b.end());
    do {
        for (int i = 0; i < n; i++)
            if (a[i] != b[i]) continue;

        prev_permutation(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return 0;

    } while (next_permutation(a.begin(), a.end()));
}