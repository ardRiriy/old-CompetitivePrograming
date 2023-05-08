#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    string s;
    cin >> s;
    int ct = 2;
    rep(i, 2){
        if(s[0] == 'x') s.erase(s.begin());
        else break;
    }

    if(s.empty()){
        cout << "Yes" << endl;
        return 0;
    }
    // cout << s << endl;
    if(s[0] == 'o') s.erase(s.begin());
    else{
        cout << "No" << endl;
        return 0;
    }
    // cout << s << endl;

    if(s.empty()){
        cout << "Yes" << endl;
        return 0;
    }

    rep(i, s.size()){
        if(s[i] == 'o') {
            if(ct==0) ct = 2;
            else {
                cout << "No" << endl;
                return 0;
           }
        }
        else{
            if(ct == 0) {
                cout << "No" << endl;
                return 0;
            }
            ct--;
        }
    }
    cout << "Yes" << endl;
    return 0;
}


