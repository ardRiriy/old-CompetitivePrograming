#include <bits/stdc++.h>
using namespace std;

long f(long x,int i){
	long z = pow(10, i+1);
	double fl = (double)x/z;
	//cout << fl << endl;
	return (std::round(fl) * z);
}

int main() {
	long x;
	int k;
	cin >> x;
	cin >> k;
	
	for(int j = 0; j < k; j++){
		// cout << x << endl;
		x = f(x, j);
	}
	
	cout << x << endl;
	
}
