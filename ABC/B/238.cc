#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int now = 0;
    int n;
    vector<int> v;
    cin >> n;
    v.push_back(now);
    v.push_back(360);
    rep(i, n){
        int a;
        cin >> a;
        now += a;
        now %= 360;
        v.push_back(now);
    }

    sort(v.begin(), v.end());
    int ans = 0;
    rep(i, v.size() - 1){
        ans = max(ans, v[i+1] - v[i]);
    }
    cout << ans << endl;
    return 0;
}

