//全然ダメ

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	
	int k;
	vector<vector<int>> vec(m, vector<int>(n));
	for(int i = 0; i < m; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> vec.at(i).at(j);
		}
	}
	
	bool judge_all = true;
	for(int hito = 1; hito < n+1; hito++){
		for(int aite = 1; aite < n+1; aite++){
			if(hito == aite){
				continue;
			}
			bool judge = false;
			for(int i = 0; i < m; i++){
				if(vec.at(i).contains(aite)){
					judge = true;
					break;
				}
			}

			if(!judge){
				judge_all = false;
				break;
			}
		}
	}
	if(judge_all){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
	

