#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A, B;
int m, M;
int ten;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B;

  ten = 1;
  while(A) {
    if(A%10 == 5 || A%10 == 6) {
      m += ten*5;
      M += ten*6;
    } else {
      m += ten*(A%10);
      M += ten*(A%10);
    }
    A /= 10;
    ten *= 10;
  }
  ten = 1;
  while(B) {
    if(B%10 == 5 || B%10 == 6) {
      m += ten*5;
      M += ten*6;
    } else {
      m += ten*(B%10);
      M += ten*(B%10);
    }
    B /= 10;
    ten *= 10;
  }

  cout << m << " " << M;

  return 0;
}