#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
	long a,b,c,d,e,f;
	
	long m = 998244353;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	cin >> f;
	
	a = a%m;
	b = b%m;
	c = c%m;
	d = d%m;
	e = e%m;
	f = f%m;

	long ans = (a * b % m * c % m - d * e % m * f) % m;
	if(ans < 0){
		cout << ans+m << endl;
	}else{
		cout << ans << endl;
	}
}
