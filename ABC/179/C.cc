#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int k = i * j;
            if (k < n)
                ans += 1;
            else
                break;
        }
    }

    cout << ans << endl;

    return 0;
}
