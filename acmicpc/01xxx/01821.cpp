#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, F;
int A[11];
int B[1000001];
int C[11][11];
int sum;

int DFS(int n, int sum) {
  if(sum > F) return 0;
  if(n == N) {
    if(sum == F) return 1;
    return 0;
  }
  for(int i = 1; i <= N; i++) {
    if(!B[i]) {
      B[i] = 1;
      A[n] = i;
      if(DFS(n+1, sum + C[N-1][n]*i)) return 1;
      B[i] = 0;
    }
  }
  return 0;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 0; i <= 10; i++) {
    C[i][0] = C[i][i] = 1;
  }
  for(int i = 2; i <= 10; i++) {
    for(int j = 1; j < i; j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  cin >> N >> F;
  DFS(0, 0);
  for(int i = 0; i < N; i++) {
    cout << A[i] << " ";
  }

  return 0;
}