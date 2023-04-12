#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    int k = 0;
    cin >> n >> m;
    vector<string> hutu(n);
    string s;

    for (int i = 0; i < n; i++) cin >> hutu[i];
    for (int i = 0; i < m; i++) {
        cin >> s;
        while (true) {
            if (hutu[k] == s) {
                k += 1;
                cout << "Yes" << endl;
                break;
            } else {
                cout << "No" << endl;
                k += 1;
            }
        }
    }
}