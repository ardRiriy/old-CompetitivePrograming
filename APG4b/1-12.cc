#include <bits/stdc++.h>
using namespace std;
 
int main() {
	string S;
 	cin >> S;
 
	int len = S.size();
	int sum = 1;
	for(int i = 0; i < len; i++){
		if(S.at(i) == '+'){
			sum += 1;
		}else if(S.at(i) == '-'){
			sum -= 1;
		}
	}
	cout << sum << endl;
}
