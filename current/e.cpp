#include <bits/stdc++.h>
using namespace std;

const long long INF = LONG_LONG_MAX; 

long long N, D, P;
vector<long long> F(200001, 0);

vector<long long> dp(200001, INF);

int main() {
  cin >> N >> D >> P;
  for(int i = 0; i < N; i++) {
    cin >> F[i];
  }
  
  dp[0] = 0;
  
  for(int i = 0; i <= N; i++) {
    if(i - D >= 0) {
      dp[i] = min(dp[i-1] + F[i-1], dp[i-D] + P); 
    }
    else {
      dp[i] = dp[i-1] + F[i-1];
    }
  }

  cout << dp[N] << endl;
  
  return 0;
}