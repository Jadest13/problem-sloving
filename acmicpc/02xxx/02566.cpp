#include <iostream>

using namespace std;

int A[10][10];
int M = -1, R, C;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) {
      cin >> A[i][j];
      if(A[i][j] > M) {
        M = A[i][j];
        R = i;
        C = j;
      }
    }
  }

  cout << M << "\n";
  cout << R << " " << C;

}