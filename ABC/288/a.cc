#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> vec(n, vector<int>(2));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) cin >> vec[i][j];
  }

  for (int i = 0; i < n; i++) {
    cout << vec[i][0] + vec[i][1] << endl;
  }
}