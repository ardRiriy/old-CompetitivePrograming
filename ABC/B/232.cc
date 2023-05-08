#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
	string s;
	cin >> s;
	string t;
	cin >> t;

	rep(i, 27){
		if(s == t){
			cout << "Yes" << endl;
			return 0;
		}
		rep(j, s.size()){
			if(s[j] == 'z'){
				s[j] = 'a';
				continue;
			}
			s[j] += 1;
		}
	}
	cout << "No" << endl;
	return 0;
}
