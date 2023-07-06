#include <iostream>
#include <algorithm>

using namespace std;

int A[5], a;
int R[2];

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 4; j++) {
      cin >> a;
      A[i] += a;
    }
    if(A[i] > R[1]) {
      R[1] = A[i];
      R[0] = i+1;
    }
  }
  cout << R[0] << " " << R[1];

  return 0;
}