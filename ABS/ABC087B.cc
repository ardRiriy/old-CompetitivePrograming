#include <iostream>

int main()
{
    int a, b, c, x, ans;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> x;
    
    ans = 0;

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            for(int k = 0; k <= c; k++){
                int money = i*500 + j*100 + k*50;
                if(money == x){
                    ans++;
                }
            }
        }
    }

    std::cout << ans << std::endl;
}