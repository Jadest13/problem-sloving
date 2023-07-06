#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[9];
int R[9];
int V[9];

void F(int n, int k) {
  if(n == k) {
    for(int j = 1; j <= M; j++) {
      cout << R[j] << " ";
    }
    cout << "\n";
    return;
  }
  for(int i = 1; i <= N; i++) {
    if(V[i]) continue;
    V[i] = 1;
    R[k+1] = A[i];
    F(n, k+1);
    V[i] = 0;
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  sort(A+1, A+N+1);
  F(M, 0);

  return 0;
}