#include <bits/stdc++.h>
#include <map>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	map<int, int, greater<int>> mp{};
	int l=0;
	for(int i=0; i < n; i++){
		cin >> l;
		mp[l] = 1 + mp[l];
	}

	auto end=mp.end(), begin=mp.begin();	
	for(auto iter=begin; iter !=end; iter++){
		cout << iter->second << endl;
	}

	for(int k = 0; k < (n-mp.size()); k++){
		cout << "0" << endl;
	}
}


