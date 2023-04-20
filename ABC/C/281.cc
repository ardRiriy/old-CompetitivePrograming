#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;

    long long all = 0;
    vector<int> vec(n);
    for (long long i = 0; i < n; i++) {
        cin >> vec[i];
        all += vec[i];
    }

    long long s = t % all;

    for (int i = 0; i < n; i++) {
        if (s - vec[i] < 0) {
            cout << i + 1 << " " << s << endl;
            return 0;
        } else {
            s -= vec[i];
        }
    }
}