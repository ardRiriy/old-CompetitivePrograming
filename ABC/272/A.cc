#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	std::cin >> n;
	
	int sum, i, l;
	sum = 0;
	i = 0;
	while(std::cin>>l){
		sum += l;
		i++;
		if(i >= n){
		break;
		}
	}
	
	cout << sum << endl;
}
