#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  string s;
  cin >> s;
  int ans = 1;
  for (int i = 0; i < size(s); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      cout << ans << endl;
      break;
    }
    ans++;
  }
  /* // m*nの2重配列への標準入力
  vector<vector<int>> vec(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> vec[i][j];
  } */

  return 0;
}

/* // vectorの中に期待する要素が含まれているかを返す
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance(vec.begin(), itr);
  if (index != vec.size())
    return 1;
  else
    return 0;
} */