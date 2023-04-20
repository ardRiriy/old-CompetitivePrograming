#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    set<int> f;
    for (int i = 0; i < 5; i++) {
        cin >> a;
        f.insert(a);
    }
    cout << f.size() << endl;

    return 0;
}