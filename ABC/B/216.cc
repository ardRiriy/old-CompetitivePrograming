#include <bits/stdc++.h>

// #define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
    int N;
    cin >> N;
    set<string> st;
    rep(i, N){
        string s, t;
        cin >> s >> t;
        s = s + " " + t;
        st.insert(s);
    }
    if(st.size() == N) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}

