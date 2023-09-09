#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n); i >= 0; i--)
#define itrep(itr, stl) for(auto itr = stl.begin(); itr != stl.end(); itr++)
#define Vec2D(type, n, m, val) vector<vector<type>>(n, vector<type>(m, val))
#define print(x) cout << x << endl
#define all(stl) stl.begin(), stl.end()
const int INF = LLONG_MAX;
const int N_INF = LLONG_MIN;
using namespace std;
class UnionFind { 
    private: map<int, int> uf;
    public:
    int root(int n) { if (uf.find(n) == uf.end()) uf[n] = -1; if (uf[n] < 0) return n; else return uf[n] = root(uf[n]); }
    bool connected(int a, int b) { return root(a) == root(b); }
    void marge(int a, int b) { int root_a = root(a); int root_b = root(b); if (root_a != root_b) { if (uf[root_a] > uf[root_b]) swap(root_a, root_b); uf[root_a] += uf[root_b]; uf[root_b] = root_a; }}
    int size(int n) { return -uf[root(n)]; }
};
bool chmin(int &a, int b) { if (a > b) { a = b; return true; } return false; }
bool chmax(int &a, int b) { if (a < b) { a = b; return true; } return false; }
int power(int x, int n) { int result = 1; while(n > 0){ if((n & 1) == 1){ result *= x; } x *= x; n >>= 1; } return result; } /*x^nを計算*/
int b_search(vector<int>& v, int k) { int ng = -1, ok = v.size(); while (abs(ng - ok) > 1) { int mid = ok + (ng - ok) / 2; if (v[mid] >= k) ok = mid; else ng = mid; } return ok; }

vector<vector<int>> c(3, vector<int>(3));

bool disapoint(vector<int> &order){
    vector<vector<bool>> ck(3, vector<bool>(3, false));
    rep(i, 9){
        if(order[i] == 0){
            ck[0][0] = true;
            if(ck[0][1] && ck[0][2]){
                if(c[0][1] == c[0][2]){
                    return true;
                }
            }
            if(ck[1][1] && ck[2][2]){
                if(c[1][1] == c[2][2]){
                    return true;
                }
            }
            if(ck[1][0] && ck[2][0]){
                if(c[1][0] == c[2][0]){
                    return true;
                }
            }
        }else if(order[i] == 1){
            ck[0][1] = true;
            if(ck[0][0] && ck[0][2]){
                if(c[0][0] == c[0][2]){
                    return true;
                }
            }
            if(ck[1][1] && ck[2][1]){
                if(c[1][1] == c[2][1]){
                    return true;
                }
            }
        }else if(order[i] == 2){
            ck[0][2] = true;
            if(ck[0][1] && ck[0][0]){
                if(c[0][1] == c[0][0]){
                    return true;
                }
            }
            if(ck[1][1] && ck[2][0]){
                if(c[1][1] == c[2][0]){
                    return true;
                }
            }
            if(ck[1][2] && ck[2][2]){
                if(c[1][2] == c[2][2]){
                    return true;
                }
            }
        } else if(order[i] == 3){
            ck[1][0] = true;
            if(ck[0][0] && ck[2][0]){
                if(c[0][0] == c[2][0]){
                    return true;
                }
            }
            if(ck[1][2] && ck[1][1]){
                if(c[1][2] == c[1][1]){
                    return true;
                }
            }
        }else if(order[i] == 4){
            ck[1][1] = true;
            if(ck[0][1] && ck[2][1]){
                if(c[0][1] == c[2][1]){
                    return true;
                }
            }
            if(ck[0][2] && ck[2][0]){
                if(c[0][2] == c[2][0]){
                    return true;
                }
            }
            if(ck[0][0] && ck[2][2]){
                if(c[0][0] == c[2][2]){
                    return true;
                }
            }
            if(ck[1][0] && ck[1][2]){
                if(c[1][0] == c[1][2]){
                    return true;
                }
            }
        }else if(order[i] == 5){
            ck[1][2] = true;
            if(ck[1][0] && ck[1][1]){
                if(c[1][0] == c[1][1]){
                    return true;
                }
            }
            if(ck[0][2] && ck[2][2]){
                if(c[0][2] == c[2][2]){
                    return true;
                }
            }
        } else if(order[i] == 6){
            ck[2][0] = true;
            if(ck[1][0] && ck[0][0]){
                if(c[1][0] == c[0][0]){
                    return true;
                }
            }
            if(ck[2][1] && ck[2][2]){
                if(c[2][1] == c[2][2]){
                    return true;
                }
            }
            if(ck[1][1] && ck[0][2]){
                if(c[1][1] == c[0][2]){
                    return true;
                }
            }
        } else if(order[i] == 7){
            ck[2][1] = true;
            if(ck[2][0] && ck[2][2]){
                if(c[2][0] == c[2][2]){
                    return true;
                }
            }
            if(ck[1][1] && ck[0][1]){
                if(c[1][1] == c[0][1]){
                    return true;
                }
            }
        }else {
            ck[2][2] = true;
            if(ck[2][0] && ck[2][1]){
                if(c[2][0] == c[2][1]){
                    return true;
                }
            }
            if(ck[0][0] && ck[1][1]){
                if(c[0][0] == c[1][1]){
                    return true;
                }
            }
            if(ck[1][2] && ck[0][2]){
                if(c[1][2] == c[0][2]){
                    return true;
                }
            }
        }
    }
    return false;
}


void solve() {
    // hogehoge

    rep(i, 3){
        rep(j, 3){
            cin >> c[i][j];
        }
    }

    vector<int> order(9);
    rep(i, 9) order[i] = i;

    int total_permutations = 0;
    int disappointed_count = 0;

    do{
        total_permutations ++;
        if(disapoint(order)){
            disappointed_count++;
        }
    }while(next_permutation(all(order)));

    double ans = (double)(total_permutations - disappointed_count) / total_permutations;
    print(ans);
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
