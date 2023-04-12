// TLE(知ってた)
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    map<int, int> mp;
    for (int i = 1; i <= 2 * *max_element(vec.begin(), vec.end()) + 1; i++)
        mp[i] = int(log2(i));
    cout << 0 << endl;
    for (int k = 0; k < n; k++) {
        cout << mp[2 * vec[k]] << endl;
        cout << mp[2 * vec[k] + 1] << endl;
    }
    return 0;
}