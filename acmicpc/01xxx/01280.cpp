#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 200001
#define MOD 1000000007

using namespace std;
using LL = long long;

int N;
int X;
LL SEG_D[MAX*4];
LL SEG_C[MAX*4];
LL R = 1;

LL segDistQuery(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG_D[n];

  int m = (s+e)/2;
  return segDistQuery(n*2, s, m, l, r) + segDistQuery(n*2+1, m+1, e, l, r);
}

LL segDistUpdate(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG_D[n];
  if(s==e) return SEG_D[n] = SEG_D[n] + a;

  int m = (s+e)/2;
  return SEG_D[n] = segDistUpdate(n*2, s, m, i, a) + segDistUpdate(n*2+1, m+1, e, i, a);
}

LL segCountQuery(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG_C[n];

  int m = (s+e)/2;
  return segCountQuery(n*2, s, m, l, r) + segCountQuery(n*2+1, m+1, e, l, r);
}

LL segCountUpdate(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG_C[n];
  if(s==e) return SEG_C[n] = SEG_C[n] + a;

  int m = (s+e)/2;
  return SEG_C[n] = segCountUpdate(n*2, s, m, i, a) + segCountUpdate(n*2+1, m+1, e, i, a);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> X;
    X++;

    if(i) {
      LL ldist = 0, rdist = 0;
      LL lcnt = 0, rcnt = 0;
      LL lr = 0, rr = 0;

        ldist = segDistQuery(1, 1, MAX-1, 1, X-1);
        lcnt = segCountQuery(1, 1, MAX-1, 1, X-1);
        lr = X*lcnt - ldist;
        lr %= MOD;
        rdist = segDistQuery(1, 1, MAX-1, X+1, MAX-1);
        rcnt = segCountQuery(1, 1, MAX-1, X+1, MAX-1);
        rr = rdist - X*rcnt;
        rr %= MOD;

      R *= (lr+rr)%MOD;
      R %= MOD;
    }

    segDistUpdate(1, 1, MAX-1, X, X);
    segCountUpdate(1, 1, MAX-1, X, 1);
  }

  cout << R;

  return 0;
}