#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

bool ch(char c){
    if(c == 'a' || c == 't' || c == 'c' || c == 'd' || c == 'o' || c == 'e' || c == 'r') return true;
    return false;
}
signed main() {
    string s, t;
    cin >> s >> t;
    
    map<char, int> ms, mt;
    rep(i, 26){
        ms['a' + i] = 0;
        mt['a' + i] = 0;
    }
    rep(i, s.size()){
        ms[s[i]]++;
        mt[t[i]]++;
    }
    
    for(auto itr = ms.begin(); itr != ms.end(); itr++){
        if(itr->first == '@') continue;
        int diff = itr->second - mt[itr->first];
        if(diff != 0){
            if(ch(itr->first)){
                if(diff > 0) mt['@'] -= diff;
                else ms['@'] += diff;
            } else{
                cout << "No" << endl;
                return 0;
            }
        }        
    }
    
    if(ms['@'] >= 0 && mt['@'] >= 0 && ms['@'] == mt['@']) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;

}
