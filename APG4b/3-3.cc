#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    int k;
    LOOP(i, n) {
        cin >> k;
        mp[k]++;
    }

    int key;
    int max = 0;
    for (auto p : mp) {
        if (max < p.second) {
            key = p.first;
            max = p.second;
        }
    }
    PRINT(key << " " << max)

    return 0;
}
