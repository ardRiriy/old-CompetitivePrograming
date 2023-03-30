#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        s.insert(i + 1);
    }

    for (int i = 0; i < n; i++) {
        if (vec[i] != -1) {
            vec[vec[i] - 1] = -1;
            s.erase(vec[i]);
        }
    }
    cout << size(s) << endl;

    for (auto itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }

    cout << endl;
    return 0;
}