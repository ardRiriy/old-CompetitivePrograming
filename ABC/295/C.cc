#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (vec[i] == vec[i + 1]) {
            ans++;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}
