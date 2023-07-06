#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[101], C[101];
int sum;
int DP[101][10001];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for(int i = 1; i <= N; i++) {
    cin >> C[i];
    sum += C[i];
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j <= sum; j++) {
      if(j - C[i] >= 0) {
        DP[i][j] = max(DP[i][j], DP[i-1][j-C[i]] + A[i]);
      }
      DP[i][j] = max(DP[i][j], DP[i-1][j]);
    }
  }

  for(int i = 0; i <= sum; i++) {
    if(DP[N][i] >= M) {
      cout << i << "\n";
      break;
    }
  }

  return 0;
}