#include <iostream>
#include <algorithm>

#define MAX 8+1

using namespace std;

int N;
int A[MAX];
int V[MAX];
int R;

void F(int n, int k, int a, int l) {
  if(n == k) {
    R = max(R, a);
    return;
  }
  for(int i = 1; i <= N; i++) {
    if(V[i]) continue;
    V[i] = 1;
    F(n, k+1, a + abs(A[l]-A[i]), i);
    V[i] = 0;
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for(int i = 1; i <= N; i++) {
    V[i] = 1;
    F(N, 1, 0, i);
    V[i] = 0;
  }
  cout << R;

  return 0;
}