#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;

    bool ans = false;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == "and" || s == "not" || s == "that" || s == "the" ||
            s == "you") {
            ans = true;
            break;
        }
    }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}