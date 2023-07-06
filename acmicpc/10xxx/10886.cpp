#include <iostream>
#include <algorithm>

using namespace std;

int N, A, R;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A;
    R+=A;
  }
  if(R > N/2) cout << "Junhee is cute!";
  else cout << "Junhee is not cute!";

  return 0;
}