#include <bits/stdc++.h>

#include <string>
#include <vector>
using namespace std;

int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance(vec.begin(), itr);
  if (index != vec.size()) {  // 発見できたとき
    return 1;
  } else {  // 発見できなかったとき
    return 0;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> vec(m);
  for (int i = 0; i < m; i++) {
    cin >> vec[i];
  }

  std::vector<int> tmp(n);
  tmp.clear();

  for (int i = 0; i < n; i++) {
    if (vector_finder(vec, i + 1) == 1) {
      tmp.insert(tmp.begin(), i + 1);
    } else {
      cout << i + 1 << " ";
      for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i] << " ";
      }
      tmp.clear();
    }
  }
  cout << endl;
}
