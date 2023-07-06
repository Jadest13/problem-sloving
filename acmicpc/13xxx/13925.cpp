#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define LL long long

using namespace std;

int N, M;
int A, B, C, D;
LL ARR[MAX];
LL SEG[MAX*4], LAZ[MAX*4];

LL seg_init(int n, int s, int e) {
  if(s==e) return SEG[n] = ARR[s];
  int m = (s+e)>>1;
  return SEG[n] = seg_init(n*2, s, m) + seg_init(n*2+1, m+1, e);
}

void seg_lazy(int n, int s, int e) {
  if(LAZ[n] != 0) {
    SEG[n] += (e-s+1)*LAZ[n];
    if(s != e) {
      LAZ[n*2] += LAZ[n];
      LAZ[n*2+1] += LAZ[n];
    }
    LAZ[n] = 0;
  }
}

void seg_add(int n, int s, int e, LL l, LL r, LL a) {
  seg_lazy(n, s, e);
  if(e < l || r < s) return;
  if(l <= s && e <= r) {
    SEG[n] += (e-s+1)*a;
    if(s != e) {
      LAZ[n*2] += a;
      LAZ[n*2+1] += a;
    }
    return;
  }

  int m = (s+e)>>1;
  seg_add(n*2, s, m, l, r, a);
  seg_add(n*2+1, m+1, e, l, r, a);
  SEG[n] = SEG[n*2] + SEG[n*2+1];
}

LL seg_sum(int n, int s, int e, LL l, LL r) {
  seg_lazy(n, s, e);
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return seg_sum(n*2, s, m, l, r) + seg_sum(n*2+1, m+1, e, l, r);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }
  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A;
    switch(A) {
      case 1 :
        
        break;
    }
  }

  return 0;
}