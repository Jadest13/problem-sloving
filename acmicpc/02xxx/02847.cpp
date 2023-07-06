#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[101];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for(int i = N-1; i >= 1; i--) {
    if(A[i] >= A[i+1]) {
      R += A[i] - A[i+1] + 1;
      A[i] = A[i+1]-1;
    }
  }

  cout << R;

  return 0;
}