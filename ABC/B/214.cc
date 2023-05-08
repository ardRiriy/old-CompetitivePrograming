#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;



signed main() {
	int s, t;
	cin >> s >> t;
	int ans = 0;
	rep(a, 1000){
		rep(b, 1000){
			rep(c, 1000){
				if(a + b + c <= s && a * b * c <= t)ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

