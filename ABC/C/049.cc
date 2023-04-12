#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    string dream = "maerd";
    string erase = "esare";
    string dreamer = "remaerd";
    string eraser = "resare";

    while (true) {
        if (s.size() == 0) {
            cout << "YES" << endl;
            break;
        }
        if (equal(begin(dream), end(dream), begin(s))) {
            s.erase(s.begin(), s.begin() + 5);
        } else if (equal(begin(erase), end(erase), begin(s))) {
            s.erase(s.begin(), s.begin() + 5);
        } else if (equal(begin(dreamer), end(dreamer), begin(s))) {
            s.erase(s.begin(), s.begin() + 7);
        } else if (equal(begin(eraser), end(eraser), begin(s))) {
            s.erase(s.begin(), s.begin() + 6);
        } else {
            cout << "NO" << endl;
            break;
        }
    }

    return 0;
}
