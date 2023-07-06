#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000003

using namespace std;

int N, K;
int DP[1001][1001];

int dp(int n, int k) {
  if(n <= 0 || n < 2*k) return 0;
  if(k == 1) return n;
  if(DP[n][k] != -1) return DP[n][k];
  return DP[n][k] = (dp(n-2, k-1) + dp(n-1, k)) % MOD;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= K; j++) {
      DP[i][j] = -1;
    }
  }

  cout << dp(N, K);

  return 0;
}