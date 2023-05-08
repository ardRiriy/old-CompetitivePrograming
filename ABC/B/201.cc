#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int N;
    cin >> N;
    int h_max = 0; string max_name;
    int h_two = 0; string two_name;
    rep(i, N){
        int t;
        string s;
        cin >> s >> t;
        if(t > h_max){
            h_two = h_max;
            two_name = max_name;
            h_max = t;
            max_name = s;
        }else if(t > h_two){
            h_two = t;
            two_name = s;
        }
    }
    cout << two_name << endl;
    return 0;
}
