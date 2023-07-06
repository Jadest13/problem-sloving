#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A, B;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  A = N/5;
  N %= 5;
  B = N/2;
  N %= 2;
  if(N) {
    A -= 1;
    B += 3;
  }

  cout << ((A<0)?-1:(A+B));

  return 0;
}