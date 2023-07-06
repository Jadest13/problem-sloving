#include <iostream>
#include <algorithm>

using namespace std;

int N;
int r[501], c[501];
long DP[501][501];

int main(void) {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> r[i] >> c[i];
  }

  for(int b = 1; b < N; b++) {
    for(int i = 1; i <= N-b; i++) {
      int j = i+b;
      DP[i][j] = 1e12;
      for(int k = i; k < j; k++) {
        DP[i][j] = min(DP[i][j], DP[i][k] + DP[k+1][j] + r[i]*r[k+1]*c[j]);
      }
    }
  }

  cout << DP[1][N];


  exit(0);
}