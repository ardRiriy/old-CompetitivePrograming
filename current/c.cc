#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int n,m;
    cin >> n >>m;
    

    vector<string> vec(n);
    rep(i, n) cin >> vec[i];
    
    sort(vec.begin(), vec.end());

    do{
        bool ck = true;
        rep(i, n-1){
            int diff = 0;
            rep(k, m){
               if(vec[i][k] != vec[i+1][k]) diff++;
            }
            if(diff != 1) {
                ck = false;
                break;
            }
        }
        if(ck){
            cout << "Yes" << endl;
            return 0;
        }
    }while(next_permutation(vec.begin(), vec.end()));
    
    cout << "No" << endl;
    return 0;
}


