
/*斜めの正方形に対応できてない*/
#include <bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<vector<int>> vec(9, vector<int>(9));
	
	string s;
	char c;
	for(int i=0; i<9; i++){
		cin >> s;
		for(int j=0; j<9;j++){
			c = s[j];
			if(c == '#'){
				vec[i][j] = 1;
			}else{
				vec[i][j] = 0;
			}
		}
	}

	int ans = 0;
	
	for(int i=0; i<9; i++){
		for(int j=0; j<8; j++){
			for(int l=1; l<9-j; l++){
				if(vec[i][j]==1 && vec[i][j+l]==1 && vec[i+l][j]==1 && vec[i+l][j+l]==1){
					ans+=1;
				}
			}
		}
	}
	cout << ans << endl;
}
