/*これはTLE*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);	
	
	for(int j=0;j<n;j++){
		cin >> a.at(j);
	}
	sort(a.begin(),a.end());
	
	int head;
	int kazu;
	int d;
	int max=0;
	int m = n;
	for(int k = 0; k < n; k++){
		head = a.back();
		if(max==0){
			max = head;
		}else if(max==head){
			cout << "0" << endl;
			continue;
		}
		if(head == 0){
			cout << "0" << endl;
			continue;
		}
		kazu = count(a.begin(), a.end(), head);
		d = m-kazu;
		m = m-kazu;
		a.resize(d);
		cout << kazu << endl;
	}
}		


