#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

int T;
int N, M;
LL a;
LL A[1001], B[1001];
LL R;

LL F(LL n) {
  LL ret = 0;
  int l = 0, r = 0;
  while(r <= M) {
    if(B[r]-B[l] < n) {
      r++;
    } else if(B[r]-B[l] >= n) {
      if(B[r]-B[l] == n) {
        ret++;
      }
      l++;
    }
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> a;
    A[i] = A[i-1] + a;
  }
  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> a;
    B[i] = B[i-1] + a;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 1; j <= N-i; j++) {
      if(A[j]-A[j-i-1] <= T) {
        R += F(T-(A[j]-A[j-i-1]));
      }
    }
  }

  return 0;
}