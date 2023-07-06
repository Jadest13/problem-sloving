#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, M;
int W, I, J;
int ARR[MAX];
int SEG[MAX*4];

int seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] = a;

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i, a) + seg_update(n*2+1, m+1, e, i, a);
}

int seg_query(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return seg_query(n*2, s, m, l, r) + seg_query(n*2+1, m+1, e, l, r);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
    seg_update(1, 1, N, i, ARR[i]%2);
  }
  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> W >> I >> J;
    if(W==1) {
      seg_update(1, 1, N, I, J%2);
    } else {
      int ret = seg_query(1, 1, N, I, J);
      cout << ((W%2)?ret:J-I+1-ret) << "\n";
    }
  }

  return 0;
}