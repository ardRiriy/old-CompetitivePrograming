#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int n;
    cin >> n;
    string name[n][2];
    rep(i, n) {
        cin >> name[i][0];
        cin >> name[i][1];
    }
    rep(i, n){
        bool s = false, t = false;
        rep(j, n){
            if(i == j) continue;
            if(name[i][0] == name[j][0]) t = true;
            if(name[i][0] == name[j][1]) t = true;
            
            if(name[i][1] == name[j][0]) s = true;
            if(name[i][1] == name[j][1]) s = true;
        }
        if(s && t){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
