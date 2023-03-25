#include <bits/stdc++.h>

#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  /* // m*nの2重配列への標準入力
  vector<vector<int>> vec(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) cin >> vec[i][j];
  } */
  int n;
  string s;
  cin >> n;
  cin >> s;

  set<tuple<int, int>> st{{0, 0}};
  int posX = 0;
  int posY = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      posX += 1;
    } else if (s[i] == 'L') {
      posX -= 1;
    } else if (s[i] == 'U') {
      posY += 1;
    } else {
      posY -= 1;
    }
    st.insert({posX, posY});
  }
  if (n + 1 != st.size()) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
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