#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int A[5];
int ret;

void F() {
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 0; i < 5; i++) {
    cin >> A[i];
    ret += A[i] * A[i];
  }

  cout << ret % 10;
  

  return 0;
}