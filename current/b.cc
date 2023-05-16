#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];
    
    vector<int> ans;
    rep(i, n-1){
        if(abs(vec[i] - vec[i+1]) == 1){
            ans.push_back(vec[i]);
        }else{
            if(vec[i] < vec[i+1]){
                for(int k = vec[i];k < vec[i+1];k++){
                    ans.push_back(k);
                }
            } else{
                for(int k = vec[i]; k > vec[i+1]; k--){
                    ans.push_back(k);
                }
            }
        }
    }

    ans.push_back(vec[n-1]);

    for(int i: ans) cout << i << " ";
    cout << endl;

    return 0;
}
