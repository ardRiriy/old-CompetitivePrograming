#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int a = 1; a < n; a++) {
        for (int b = 1; a * b < n; b++) {
            mp[a * b]++;
        }
    }

    int ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        int cd = n - itr->first;
        if (mp[cd] != 0) ans += mp[cd] * itr->second;
    }
    cout << ans << endl;
    return 0;
}
