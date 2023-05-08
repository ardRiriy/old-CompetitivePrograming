#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    string s;
    cin >> s;

    bool big = false, small = false;
    set<char> c;

    rep(i, s.size()){
        if(s[i] >= 'A' && s[i] <= 'Z') big =true;
        else if(s[i] >= 'a' && s[i] <= 'z') small = true;
        c.insert(s[i]);
    }

    if(big && small && c.size() == s.size()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
