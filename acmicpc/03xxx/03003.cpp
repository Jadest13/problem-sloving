#include <iostream>
#include <cstdio>

using namespace std;

int K, Q, L, B, N, P;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> K >> Q >> L >> B >> N >> P;

  printf("%d %d %d %d %d %d", 1-K, 1-Q, 2-L, 2-B, 2-N, 8-P);

  return 0;
}