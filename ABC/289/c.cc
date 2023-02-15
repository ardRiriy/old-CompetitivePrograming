#include <bits/stdc++.h>

#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> vec(m, vector<int>(n));

  for (int i = 0; i < m; i++) {
    int n;
    cin >> n;
    for (int j = 0; j < n; j++) cin >> vec[i][j];
  }

  int ans = 0;
  for (int bit = 0; bit < (1 << m); bit++) {
    set<int> st;
    for (int i = 0; i < m; i++) {
      if ((bit >> i) & 1 == 1) {
        for (int j = 0; j < n; j++) {
          if (vec[i][j] != 0) st.insert(vec[i][j]);
        }
      }
    }
    if ((int)st.size() == n) ans += 1;
  }

  cout << ans << endl;
}