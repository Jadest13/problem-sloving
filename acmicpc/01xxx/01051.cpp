#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int N, M;
string S;
int A[51][51];
int R;

int F(int x, int y, int d) {
  if(x+d > M) return 0;
  if(y+d > N) return 0;
  if(A[x][y] == A[x+d][y] && A[x][y] == A[x][y+d] && A[x][y] == A[x+d][y+d]) {
    return (d+1)*(d+1);
  }
  return 0;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= M; j++) {
      A[j][i] = S[j-1];
    }
  }
  
  for(int i = 1; i <= M; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = 0; k <= M-i; k++) {
        R = max(F(i, j, k), R);
      }
    }
  }

  cout << R;

  return 0;
}