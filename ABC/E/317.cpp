#include <bits/stdc++.h>
#include <pthread.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
const int INF = LLONG_MAX;
using namespace std;

vector<string> s; 
vector<vector<bool>> ck;
int h, w;

void solve() {
    // hogehoge
    cin >> h >> w;
    s.resize(h);
    ck.resize(h, vector<bool>(w, false));
    rep(i, h) cin >> s[i];
    
    //準備
    
    //(y, x)
    pair<int, int> start;
    {
        rep(i, h){
            rep(j, w){
                char ch = s[i][j];
                if(ch == 'S') start = {i, j};
                else if(ch == '>'){
                    for(int k = j+1; k < w; k++){
                        if(!(s[i][k] == '.' || s[i][k] == '!')) break;
                        s[i][k] = '!';
                    }
                }else if(ch == 'v'){ 
                    for(int k = i+1; k < h; k++){
                        if(!(s[k][j] == '.' || s[k][j] == '!')) break;
                        s[k][j] = '!';
                    }
                }else if(ch == '<'){
                    for(int k = j-1; k >= 0; k--){
                        if(!(s[i][k] == '.' || s[i][k] == '!')) break;
                        s[i][k] = '!';
                    }
                }else if(ch == '^'){
                    for(int k = i-1; k >= 0; k--){
                        if(!(s[k][j] == '.' || s[k][j] == '!')) break;
                        s[k][j] = '!';
                    }
                    
                }
            }
        }
    }
    
    // rep(i, h) print(s[i]); 
    //print(start.second << start.first); 
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<pair<int, int>, int>> que;
    que.push({start, 0});
    while(!que.empty()){
        auto p = que.front();
        que.pop();
        
        int depth = p.second;
        int x = p.first.second;
        int y = p.first.first;
        //print(y << " " << x << " " << depth);
        if(s[y][x] == 'G'){
            print(depth);
            return;
        }
        rep(i, 4){
            int nx = dx[i] + x, ny = dy[i] + y;
            if(nx < w && nx >= 0 && ny < h && ny >= 0){
                if((s[ny][nx] == '.' || s[ny][nx] == 'G') && !ck[ny][nx]) {
                    que.push({{ny, nx}, depth+1});
                    ck[ny][nx] = true;
                }
            }
        }
    }
    print(-1);
}

signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);
    std::cin.tie(0)->sync_with_stdio(0);
    int times = 1;
    // cin >> times;
    while (times--) solve();
    return 0;
}
