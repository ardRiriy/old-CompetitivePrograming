#include <bits/stdc++.h>

#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> vec(8, vector<int>(8));
    int y;
    string x;
    string s;
    for (int i = 0; i < 8; i++) {
        cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == '*') {
                if (j == 0)
                    x = 'a';
                else if (j == 1)
                    x = 'b';
                else if (j == 2)
                    x = 'c';
                else if (j == 3)
                    x = 'd';
                else if (j == 4)
                    x = 'e';
                else if (j == 5)
                    x = 'f';
                else if (j == 6)
                    x = 'g';
                else if (j == 7)
                    x = 'h';
                y = 8 - i;
            }
        }
    }
    cout << x << y << endl;

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