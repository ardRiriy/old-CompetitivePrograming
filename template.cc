#include <bits/stdc++.h>
using namespace std;

int main() {}

// vectorの中に期待する要素が含まれているかを返す
int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance(vec.begin(), itr);
  if (index != vec.size()) {  // 発見できたとき
    return 1;
  } else {  // 発見できなかったとき
    return 0;
  }
}