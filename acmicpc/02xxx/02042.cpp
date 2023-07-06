#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, K;
long long a, b, c;
long long A[1000001];
long long *T;

long long init(int s, int e, int n) {
  if(s == e) return T[n] = A[s];
  int m = (s+e)/2;
  return T[n] = init(s, m, n*2) + init(m + 1, e, n*2+1);
}

long long sum(int s, int e, int n, int l, int r) {
  if(l > e || r < s) return 0;
  if(l <= s && e <= r) return T[n];
  int m = (s+e)/2;
  return sum(s, m, n*2, l, r) + sum(m+1, e, n*2 + 1, l, r);
}

void update(int s, int e, int n, int i, long long a) {
  if(i < s || i > e) return;
  T[n] += a;
  if(s == e) return;
  int m = (s+e)/2;
  update(s, m, n*2, i, a);
  update(m+1, e, n*2 + 1, i, a);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> K;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int h = ceil(log2(N));
  T = new long long[1<<(h+1)];

  init(0, N-1, 1);

  for(int i = 0; i < M+K; i++) {
    cin >> a >> b >> c;
    if(a == 1) {
      long long d = c-A[b-1];
      A[b-1] = c;
      update(0, N-1, 1, b-1, d);
    } else if(a == 2) {
      cout << sum(0, N-1, 1, b-1, c-1) << "\n";
    }
  }

  return 0;
}