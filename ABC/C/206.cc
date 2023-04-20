#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;

    map<long long, long long> mp;
    vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        mp[vec[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += vec.size() - mp[vec[i]];
    }

    if (ans % 2 == 1)
        ans = ans / 2 + 1;
    else
        ans /= 2;

    cout << ans << endl;
    return 0;
}