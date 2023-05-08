#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    rep(i, min(a.size(), b.size())){
        int x, y;
        x = a[i] - '0';
        y = b[i] - '0';
        if(x + y >= 10){
            cout << "Hard" << endl;
            return 0;
        } 
    }
    cout << "Easy" << endl;
    return 0;
}



