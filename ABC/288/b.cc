#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<string> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i];
  }
  for (int i = 0; i < (n - k); i++) {
    vec.pop_back();
  }

  sort(vec.begin(), vec.end());
  for (int i = 0; i < k; i++) {
    cout << vec[i] << endl;
  }
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