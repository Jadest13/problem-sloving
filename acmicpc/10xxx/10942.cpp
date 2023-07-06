#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[2001];
int DP[2001][2001];
int S, E;

int main(void) {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
    DP[i][i] = 1;
    if(A[i-1] == A[i]) {
      DP[i-1][i] = 1;
    }
  }

  for(int i = 2; i <= N; i++) {
    for(int j = 1; j <= N-i; j++) {
      if(A[j] == A[j+i] && DP[j+1][j+i-1]) {
        DP[j][j+i] = 1;
      }
    }
  }

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> S >> E;
    cout << DP[S][E] << "\n";
  }


  exit(0);
}