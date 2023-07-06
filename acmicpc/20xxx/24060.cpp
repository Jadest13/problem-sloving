#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int A[500001];
int tmp[500001];
int res = -1;

void F2(int l, int m, int r) {
  int i = l;
  int j = m + 1;
  int t = 1;

  while(i <= m && j <= r) {
    if(A[i] <= A[j]) {
      tmp[t++] = A[i++];
    } else {
      tmp[t++] = A[j++];
    }
  }

  while(i <= m) {
    tmp[t++] = A[i++];
  }

  while(j <= r) {
    tmp[t++] = A[j++];
  }

  for(int i = l, t = 1; i <= r; i++) {
    A[i] = tmp[t++];
    if(--K == 0) {
      res = A[i];
    }
  }
}

void F1(int l, int r) {
  if(l < r) {
    int m = (l+r)/2;
    F1(l, m);
    F1(m+1, r);
    F2(l, m, r);
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  F1(1, N);

  cout << res;

  return 0;
}