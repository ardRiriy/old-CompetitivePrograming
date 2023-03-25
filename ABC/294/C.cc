#include <bits/stdc++.h>

#include <set>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  set<int> a;
  set<int> b;
  set<int> a_ans;
  set<int> b_ans;

  int tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    a.insert(tmp);
  }
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    b.insert(tmp);
  }
  for (int i = 0; i < (n + m); i++) {
    if (a.empty()) {
      b_ans.insert(i + 1);
      continue;
    } else if (b.empty()) {
      a_ans.insert(i + 1);
      continue;
    }
    if (*a.begin() < *b.begin()) {
      a_ans.insert(i + 1);
      a.erase(a.begin());
    } else {
      b_ans.insert(i + 1);
      b.erase(b.begin());
    }
  }

  for (auto itr = a_ans.begin(); itr != a_ans.end(); ++itr) {
    cout << *itr << " ";
  }
  cout << endl;
  for (auto itr = b_ans.begin(); itr != b_ans.end(); ++itr) {
    cout << *itr << " ";
  }
  cout << endl;
  return 0;
}