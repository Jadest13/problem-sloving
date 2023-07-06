#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define MOD 1000000007

int N, M, K;
long long a, b, c;
long long A[1000001];
long long *T;

long long init(int n, int s, int e) {
  if(s == e) return T[n] = A[s];
  return T[n] = (init(n*2, s, (s+e)/2) * init(n*2+1, (s+e)/2+1, e)) % MOD;
}

long long mul(int n, int s, int e, int l, int r) {
  if(l > e || r < s) return 1;
  if(l <= s && e <= r) return T[n];
  return (mul(n*2, s, (s+e)/2, l, r) * mul(n*2 + 1, (s+e)/2+1, e, l, r)) % MOD;
}

long long update(int n, int s, int e, int i) {
  if(i < s || i > e) return T[n];
  if(s == e) {
    if(i == s) {
      T[n] = A[i];
    }
    return T[n];
  }
  return T[n] = (update(n*2, s, (s+e)/2, i) * update(n*2 + 1, (s+e)/2+1, e, i)) % MOD;
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

  init(1, 0, N-1);

  for(int i = 0; i < M+K; i++) {
    cin >> a >> b >> c;
    if(a == 1) {
      A[b-1] = c;
      update(1, 0, N-1, b-1);
    } else if(a == 2) {
      cout << mul(1, 0, N-1, b-1, c-1) << "\n";
    }
  }

  return 0;
}