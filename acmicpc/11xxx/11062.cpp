#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N;
int A[1001];
int DP[1001][1001][2];

int F(int S, int E, int B) {
  
  if(DP[S][E][B] != -1) return DP[S][E][B];

  if(S == E) {
    if(B) {
      return DP[S][E][1] = A[S];
    } else {
      return DP[S][E][0] = 0;
    }
  }

  if(B) {
    return DP[S][E][1] = max(F(S+1, E, 0) + A[S], F(S, E-1, 0) + A[E]);
  } else {
    return DP[S][E][0] = min(F(S+1, E, 1), F(S, E-1, 1));
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    memset(DP, -1, sizeof(DP));
    cin >> N;
    for(int i = 1; i <= N; i++) {
      cin >> A[i]; 
    }
    cout << F(1, N, 1) << "\n";
  }

  return 0;
}