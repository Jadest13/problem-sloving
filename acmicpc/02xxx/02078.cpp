#include <iostream>
#include <algorithm>

using namespace std;

int A, B;
int X, Y;

void F(int A, int B) {
  if(A == 1) {
    Y += B-1;
    return;
  }

  if(B == 1) {
    X += A-1;
    return;
  }

  if(A > B) {
    X += A/B;
    F(A%B, B);
  } else {
    Y += B/A;
    F(A, B%A);
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;

  F(A, B);
  cout << X << " " << Y;
  
  return 0;
}