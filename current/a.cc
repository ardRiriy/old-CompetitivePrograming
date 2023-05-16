#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ct = 0, at =0;
    rep(i, n){
        if(s[i] == 'T') ct++;
        else at++;
    } 

    if(ct == at){
        if(s[n-1] == 'A') cout << "T" << endl;
        else cout << "A" << endl;
    } else if(ct > at){
        cout << "T" << endl;
    }else{
        cout <<"A" << endl;
    }
    return 0;
}
