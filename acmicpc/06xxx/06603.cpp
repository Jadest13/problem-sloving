#include <iostream>
#include <algorithm>

using namespace std;

int K;
int A[14];
int R[6];

void F(int n, int k, int i) {
  if(n == k) {
    for(int j = 0; j < 6; j++) {
      cout << R[j] << " ";
    }
    cout << "\n";
    return;
  }
  for(; i < K; i++) {
    R[k] = A[i];
    F(6, k+1, i+1);
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  while(1) {
    cin >> K;
    if(!K) break;
    for(int i = 0; i < K; i++) {
      cin >> A[i];
    }
    F(6, 0, 0);
    cout << "\n";
  }

  return 0;
}