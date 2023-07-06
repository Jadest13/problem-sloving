#include <iostream>
#include <algorithm>

#define MAX 10000001

using namespace std;

int N, M;
int A[MAX];
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  sort(A+1, A+N+1);
  int l = 1, r = N;
  while(l < r) {
    if(A[l]+A[r] == M) {
      l++;
      r--;
      R++;
    } else if(A[l]+A[r] < M) {
      l++;
    } else {
      r--;
    }
  }
  cout << R;

  return 0;
}