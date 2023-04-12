// TLE + コーナーケースでWA

#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    set<int> wait;
    set<int> called;

    for (int i = 0; i < n; i++) wait.insert(i + 1);
    int e;
    int x;
    for (int i = 0; i < q; i++) {
        cin >> e;
        if (e == 1) {
            called.insert(*wait.begin());
            wait.erase(wait.begin());
        } else if (e == 2) {
            cin >> x;
            called.erase(x);
        } else {
            cout << *called.begin() << endl;
            called.erase(called.begin());
        }
    }
    return 0;
}