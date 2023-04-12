// TLE

#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    long n, m;
    cin >> n >> m;

    long ans = -1;
    for (long b = 1; b <= n; b++) {
        for (long a = b; a >= m / b; a--) {
            if (a * b >= m && (ans == -1 || ans > a * b)) {
                ans = a * b;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
