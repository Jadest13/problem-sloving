#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T;
int A, B, C;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for(int i = 1; i <= T; i++) {
    cin >> A >> B >> C;
    if(A > B) swap(A, B);
    if(A > C) swap(A, C);
    if(B > C) swap(B, C);
    
    cout << "Scenario #" << i << ":\n";
    if(A+B <= C || !(A*A + B*B == C*C)) {
      cout << "no\n\n";
    } else {
      cout << "yes\n\n";
    }
  }

  return 0;
}