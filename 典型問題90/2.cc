#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int n;
    cin >> n;
    if(n%2 == 1) {
        return 0;
    }

    int a[n];
    set<string> ans;
    rep(i, n){
        a[i] = 0;
        if(2 * i >= n) a[i] = 1;
    }
    

    do{
        int ct = 0;
        bool ck = true;
        rep(i, n){
            if(a[i]==0) ct++;
            else ct--;
            if(ct < 0) {
                ck = false;
                break;
            }
        }

        if(ck) {
            rep(i, n){
                if(a[i] == 0) cout << "(";
                else cout << ")";
            }
            cout << endl;
        }
    }while(next_permutation(a, a+n));

}


