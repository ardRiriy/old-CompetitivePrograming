#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << s[n - 1] << endl;

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