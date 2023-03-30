#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    char tmp;
    for (int i = 1; i * 2 - 1 < s.size(); i++) {
        tmp = s[2 * i - 2];
        s[2 * i - 2] = s[2 * i - 1];
        s[2 * i - 1] = tmp;
    }
    cout << s << endl;

    return 0;
}