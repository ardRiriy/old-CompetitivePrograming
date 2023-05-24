#include <bits/stdc++.h>

#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;



signed main() {
    std::cout << std::fixed;
    std::cout << std::setprecision(20);

    int h, w;
    cin >> h >> w;
    vector<string> vec(h);

    rep(i, h) cin >> vec[i];
    
    rep(i, h){
        rep(k, w){
            if(vec[i][k] == 's'){
                //上
                if(i >= 4){
                    if(vec[i-1][k] == 'n' && vec[i-2][k] == 'u' && vec[i-3][k] == 'k' && vec[i-4][k] == 'e'){
                        rep(z, 5){
                            cout << i - z + 1<< " " << k+1 << endl;
                        }
                    return 0;
                    }
                }
                // migiue 
                if(i >= 4 && k + 4 < w){
                    if(vec[i-1][k+1] == 'n' && vec[i-2][k+2] == 'u' && vec[i-3][k+3] == 'k' && vec[i-4][k+4] == 'e'){
                        rep(z, 5){
                            cout << i - z +1<< " " <<  k+z +1 << endl;
                        }
                    return 0;
                    }
                }
                // 右k 
                if(k + 4 < w){
                    if(vec[i][k+1] == 'n' && vec[i][k+2] == 'u' && vec[i][k+3] == 'k' && vec[i][k+4] == 'e'){
                        rep(z, 5){
                            cout << i +1<< " " << k + z +1<< endl;
                        }
                    return 0;
                    }
                }
                // migi下
                if(k + 4 < w && i + 4 < h){
                    if(vec[i+1][k+1] == 'n' && vec[i+2][k+2] == 'u' && vec[i+3][k+3] == 'k' && vec[i+4][k+4] == 'e'){
                        rep(z, 5){
                            cout << i+z+1 << " " << k + z +1<< endl;
                        }
                    return 0;
                    }
                }
                // sita
                if(i + 4 < h){
                    if(vec[i+1][k] == 'n' && vec[i+2][k] == 'u' && vec[i+3][k] == 'k' && vec[i+4][k] == 'e'){
                        rep(z, 5){
                            cout << i + z + 1 << " " << k +1<< endl;
                        }
                    return 0;
                    }
                }
                // hidari sita
                if(k >= 4 && i + 4 < h){
                    if(vec[i+1][k-1] == 'n' && vec[i+2][k-2] == 'u' && vec[i+3][k-3] == 'k' && vec[i+4][k-4] == 'e'){
                        rep(z, 5){
                            cout << i + z+1 << " " << k - z +1<< endl;
                        }
                        
                    return 0;
                    }
                }

                if(k >= 4){
                    if(vec[i][k-1] == 'n' && vec[i][k-2] == 'u' && vec[i][k-3] == 'k' && vec[i][k-4] == 'e'){
                        rep(z, 5){
                            cout << i+1 << " " << k - z+1<< endl;
                        }
                    return 0;
                    }
                }
                if(k >= 4 && i >= 4){
                    if(vec[i-1][k-1] == 'n' && vec[i-2][k-2] == 'u' && vec[i-3][k-3] == 'k' && vec[i-4][k-4] == 'e'){
                        rep(z, 5){
                            cout << i-z+1 << " " << k - z +1<< endl;
                        }
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}

