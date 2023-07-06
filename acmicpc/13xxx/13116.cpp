#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T;
int A, B;
int V[1024];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    for(int i = 0; i < 1024; i++) {
      V[i] = 0;
    }
    cin >> A >> B;
    while(A > 0) {
      V[A] = 1;
      A /= 2;
    }
    while(B > 0) {
      if(V[B]) {
        break;
      }
      B /= 2;
    }
    cout << B << "0\n";
  }

  return 0;
}