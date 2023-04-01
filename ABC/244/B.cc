#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int r = 0;

    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'S') {
            if (r == 0)
                x++;
            else if (r == 1)
                y--;
            else if (r == 2)
                x--;
            else
                y++;
        } else {
            r++;
            if (r == 4) r = 0;
        }
    }

    cout << x << " " << y << endl;
    return 0;
}
