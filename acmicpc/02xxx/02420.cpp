#include <iostream>
#include <algorithm>

using namespace std;

long N, M;
long R;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  R = N - M;
  if(R < 0) cout << -R;
  else cout << R;

  return 0;
}