#include <bits/stdc++.h>
using namespace std;

int f(int k){
	if(k == 0){
		return 1;
	}
	return k * f(k-1);
}

int main() {
	int n;
	cin >> n;
	int ans = f(n);
	cout << ans << endl;
}
