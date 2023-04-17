#include <bits/stdc++.h>

using namespace std;

#define PRINT(x) cout << x << endl;
#define LOOP(i, n) for (int i = 0; i < n; i++)

// N, Mの最大値+α
const int N = 200010;
const int M = 200010;

// box[i]のは配列には，box[i]に入っているカードを格納する．
vector<vector<int>> box((N), vector<int>());
// card[i]の配列には，iがかかれたカードが入っている箱の番号を格納する．
vector<vector<int>> card((M), vector<int>());

int main() {
    int n, q;
    cin >> n >> q;

    while (q--) {
        int e;
        cin >> e;
        if (e == 1) {
            int i, j;
            cin >> i >> j;
            box[j].push_back(i);
            card[i].push_back(j);
        } else if (e == 2) {
            int i;
            cin >> i;
            sort(box[i].begin(), box[i].end());
            LOOP(j, box[i].size()) cout << box[i][j] << " ";
            cout << endl;
        } else {
            int i;
            cin >> i;
            sort(card[i].begin(), card[i].end());
            card[i].erase(unique(card[i].begin(), card[i].end()),
                          card[i].end());
            LOOP(j, card[i].size()) cout << card[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}