#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y,n;
    float ans;
    std::cin >> x >> y >> n;

    if(n % 3 == 0){
        if(x*3 > y){
            ans = y * (n/3);
        }else{
            ans = x*n;
        }
    }else if(n % 3 == 1){
        if(x*3 > y){
            ans = y * (n-1) / 3 + x;
        }else{
            ans = x*n;
        }
    }else{
        if(x*3 > y){
            ans = y * (n-2) / 3 + 2*x;
        }else{
            ans = x*n;
        }
    }

    std::cout << ans << endl;
    
}
