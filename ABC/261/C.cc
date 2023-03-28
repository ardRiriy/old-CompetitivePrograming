#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    map<string, int> mp;

    for (int i = 0; i < n; i++) {
        cin >> s;
        if (mp[s] == 0) {
            cout << s << endl;
        } else {
            cout << s << "(" << mp[s] << ")" << endl;
        }
        mp[s]++;
    }
    return 0;
}