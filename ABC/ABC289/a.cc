#include <bits/stdc++.h>

#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;
  int len = s.size();

  for (int i = 0; i < len; i++) {
    if (int(s[i]) == 48) {
      s.replace(i, 1, "1");
    } else {
      s.replace(i, 1, "0");
    }
  }
  cout << s << endl;
}
