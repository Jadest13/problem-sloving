#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[31];
int DP[31][40001];
int Q;

void F(int a, int b) {

  if(a > N || DP[a][b]) {
    return;
  }

  DP[a][b] = 1;

  F(a+1, b+A[a]);
  F(a+1, abs(b-A[a]));
  F(a+1, b);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  F(0, 0);

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> Q;
    if(Q > 15000) cout << "N ";
    else if(DP[N][Q]) cout << "Y ";
    else cout << "N ";
  }

  return 0;
}