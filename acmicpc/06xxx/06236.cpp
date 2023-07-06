#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, M;
int A[MAX];

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  int l = 0, r = 1e9;
  while(l < r) {
    int m = (l+r)>>1;
    int n = 0, sum = 0;
    int flag = 0;
    for(int i = 1; i <= N; i++) {
      if(A[i] > m) flag = 1;
      if(sum < A[i]) {
        sum = m;
        n++;
      }

      sum -= A[i];
    }

    if(!flag && n <= M) {
      r = m;
    } else {
      l = m+1;
    }
  }

  cout << r;

  return 0;
}