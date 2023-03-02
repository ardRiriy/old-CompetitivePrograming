#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  /* // m*nの2重配列への標準入力
  vector<vector<int>> vec(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> vec[i][j];
  } */
  int n;
  cin >> n;

  vector<int> vec(5 * n);
  int tmp;
  for (int i = 0; i < 5 * n; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    vec.pop_back();
    vec.erase(vec.begin());
  }
  int sum = 0;
  for (int i = 0; i < (3 * n); i++) sum += vec[i];
  std::cout << std::fixed;
  cout << setprecision(7) << (float)sum / (3 * n) << endl;

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