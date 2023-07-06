#include <iostream>
#include <algorithm>

using namespace std;

int A[] = {500, 100, 50, 10, 5, 1};
int N, R;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  N = 1000 - N;

  for(int i = 0; i < 6; i++) {
    R += N/A[i];
    N %= A[i];
  }

  cout << R;

  return 0;
}