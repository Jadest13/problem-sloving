#include <iostream>
#include <algorithm>

using namespace std;

int N, P;
int R;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  while(N--) {
    cin >> P;
    R ^= P;
  }

  if(R) cout << "koosaga";
  else cout << "cubelover";

  return 0;
}