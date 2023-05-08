#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int N;
    cin >> N;
    int vec[N] = {0};
    rep(i, 4*N-1){
        int k;
        cin >> k;
        vec[k - 1]++;
    }
    rep(i, N){
        if(vec[i] != 4){
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}

