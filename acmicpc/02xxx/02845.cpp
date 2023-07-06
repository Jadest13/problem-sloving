#include <iostream>
#include <algorithm>

using namespace std;

int L, P;
int A[5];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> L >> P;
  for(int i = 0; i < 5; i++) {
    cin >> A[i];
    cout << (A[i] - L*P) << " ";
  }
  
  return 0;
}