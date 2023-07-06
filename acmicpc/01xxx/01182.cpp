#include <iostream>
#include <algorithm>

using namespace std;

int N, S;
int A[21];
int R;

int F(int n, int k, int i, int a) {
  int ret = 0;
  if(k == n) return a == S;
  for(; i < N; i++) {
    ret += F(n, k+1, i+1, a+A[i]);
  }
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> S;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for(int i = 1; i <= N; i++) {
    R += F(i, 0, 0, 0);
  }

  cout << R;

  return 0;
}