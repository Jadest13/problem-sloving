#include <iostream>
#include <algorithm>

using namespace std;

int A[6];
int a = 2001, b = 2001;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 1; i <= 3; i++) {
    cin >> A[i];
    a = min(a, A[i]);
  }

  for(int i = 4; i <= 5; i++) {
    cin >> A[i];
    b = min(b, A[i]);
  }

  cout << a+b-50;
  
  return 0;
}