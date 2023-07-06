#include <iostream>
#include <algorithm>

using namespace std;

int K, N, M;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> K >> N >> M;
  if(K*N > M) cout << K*N - M;
  else cout << 0;

  return 0;
}