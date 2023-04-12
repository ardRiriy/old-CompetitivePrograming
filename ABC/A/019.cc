#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

int main() {
    vector<int> vec(3);
    int k;
    LOOP(i, 3) cin >> vec[i];
    sort(vec.begin(), vec.end());
    cout << vec[1] << endl;
    return 0;
}