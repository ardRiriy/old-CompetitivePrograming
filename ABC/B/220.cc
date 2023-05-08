#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;


signed main() {
	int k;
	string a, b;
	cin >> k >> a >> b;
	int t_a = 0, t_b = 0;

	rep(i, a.size()){ 
		t_a += pow(k, i) * (a[a.size()-i - 1] - '0');
	}
	rep(i, b.size()) {
		t_b += pow(k, i) * (b[b.size()-i - 1] - '0');
	}


	int ans = t_a * t_b;

	cout << ans << endl;
	return 0;
}
