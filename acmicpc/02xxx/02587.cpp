#include <iostream>
#include <algorithm>

using namespace std;

int A[5];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  for(int i = 0; i < 5; i++) {
    cin >> A[i];
    R += A[i];
  }

  sort(A, A+5);
  cout << R/5 << "\n";
  cout << A[2];
}