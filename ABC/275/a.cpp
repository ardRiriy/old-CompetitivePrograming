#include <bits/stdc++.h>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<int, int, greater<int>> mp{};
	
	int l;
	for(int i=0;i<n;i++){
		cin >> l;
		mp.insert(make_pair(l, i+1));
	}
	
	auto it = mp.begin();
	cout << it->second << endl;
}
