#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, M;
int O, S, T;
int ARR[MAX];
int SEG[MAX*4], LAZ[MAX*4];

void seg_lazy(int n, int s, int e) {
  if(LAZ[n]) {
    SEG[n] = (e-s+1)-SEG[n];
    if(s != e) {
      LAZ[n*2] = !LAZ[n*2];
      LAZ[n*2+1] = !LAZ[n*2+1];
    }
    LAZ[n] = 0;
  }
}

int seg_update(int n, int s, int e, int l, int r) {
  seg_lazy(n, s, e);
  if(e < l || r < s) return SEG[n];
  if(l <= s && e <= r) {
    if(s != e) {
      LAZ[n*2] = !LAZ[n*2];
      LAZ[n*2+1] = !LAZ[n*2+1];
    }
    return SEG[n] = (e-s+1)-SEG[n];
  }

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, l, r) + seg_update(n*2+1, m+1, e, l, r);
}

int seg_query(int n, int s, int e, int l, int r) {
  seg_lazy(n, s, e);
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return seg_query(n*2, s, m, l, r) + seg_query(n*2+1, m+1, e, l, r);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> O >> S >> T;
    if(!O) {
      seg_update(1, 1, N, S, T);
    } else {
      cout << seg_query(1, 1, N, S, T) << "\n";
    }
  }
}