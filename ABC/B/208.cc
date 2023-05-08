#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int fact(int n){
    if(n == 0) return 1;
    else return n * fact(n-1);
}

signed main() {
    int p;
    cin >> p;
    vector<int> vec(10);
    rep(i, 10){
        vec[i] = fact(i + 1);
    }
    
    int ans = 0;
    int current = 9;

    while(p != 0){
        while(vec[current] > p) current--;
        p -= vec[current];
        ans ++;
    }

    cout << ans << endl;
    return 0;
}

