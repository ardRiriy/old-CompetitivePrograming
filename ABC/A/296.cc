#include <bits/stdc++.h>

#include <map>
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
    string s;
    cin >> s;
    bool b = true;
    if (s[1] == 'F') {
        for (int i = 0; i < n; i++) {
            if ((i % 2 == 0 && s[i] == 'M') || (i % 2 == 1 && s[i] == 'F'))
                continue;
            else {
                b = false;
                cout << "No" << endl;
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if ((i % 2 == 1 && s[i] == 'M') || (i % 2 == 0 && s[i] == 'F'))
                continue;
            else {
                b = false;
                cout << "No" << endl;
                break;
            }
        }
    }
    if (b) cout << "Yes" << endl;
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