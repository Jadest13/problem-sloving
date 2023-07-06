#include <iostream>
#include <algorithm>

using namespace std;

int A[3];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while(1) {
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A+3);
    if(A[2] == 0) break;
    if(A[0] == 0 || A[0]+A[1] <= A[2]) cout << "Invalid";
    else
      if(A[0] == A[2]) cout << "Equilateral";
      else
        if(A[0] == A[1] || A[1] == A[2]) cout << "Isosceles";
        else cout << "Scalene";

    cout << "\n";
  }

  return 0;
}