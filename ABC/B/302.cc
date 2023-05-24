#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    rep(i, h) cin >>s[i];

    int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

    rep(i, h){
        rep(j, w){
            rep(k, 8){
                string str = "";
                rep(t, 5){
                    int x = i + t * dx[k];
                    int y = j + t * dy[k];
                    if(x < 0 || x >= h || y < 0 || y >= w) break;
                    else str += s[x][y];
                }
                if(str == "snuke"){
                    rep(t, 5){
                        cout << i + t * dx[k] + 1<< " " << j + t * dy[k] + 1<< endl;
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}

