#include <iostream>
#include <algorithm>

using namespace std;

int T;
int B[] = {300, 60, 10};
int R[3];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  for(int i = 0; i < 3; i++) {
    R[i] += T/B[i];
    T %= B[i];
  }

  if(T) cout << -1;
  else cout << R[0] << " " << R[1] << " " << R[2];
  
  return 0;
}