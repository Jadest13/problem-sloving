#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001

using namespace std;

int N, M;
int A, B, C, D;
int ARR[MAX];
int SEG[MAX*4], LAZ[MAX*4];

int seg_init(int n, int s, int e) {
  if(s==e) return SEG[n] = ARR[s];
  int m = (s+e)>>1;
  return SEG[n] = seg_init(n*2, s, m) ^ seg_init(n*2+1, m+1, e);
}

void seg_lazy(int n, int s, int e) {
  if(LAZ[n] != 0) {
    if((e-s+1)%2) SEG[n] ^= LAZ[n];
    if(s != e) {
      LAZ[n*2] ^= LAZ[n];
      LAZ[n*2+1] ^= LAZ[n];
    }
    LAZ[n] = 0;
  }
}

void seg_update(int n, int s, int e, int l, int r, int a) {
  seg_lazy(n, s, e);
  if(e < l || r < s) return;
  if(l <= s && e <= r) {
    if((e-s+1)%2) SEG[n] ^= a;
    if(s != e) {
      LAZ[n*2] ^= a;
      LAZ[n*2+1] ^= a;
    }
    return;
  }
  
  int m = (s+e)>>1;
  seg_update(n*2, s, m, l, r, a);
  seg_update(n*2+1, m+1, e, l, r, a);
  SEG[n] = SEG[n*2] ^ SEG[n*2+1];
}

int seg_query(int n, int s, int e, int l, int r) {
  seg_lazy(n, s, e);
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return seg_query(n*2, s, m, l, r) ^ seg_query(n*2+1, m+1, e, l, r);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> ARR[i];
  }
  seg_init(1, 0, N-1);

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> A;
    if(A == 1) {
      cin >> B >> C >> D;
      seg_update(1, 0, N-1, B, C, D);
    } else {
      cin >> B >> C;
      cout << seg_query(1, 0, N-1, B, C) << "\n";
    }
  }
}