#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define INF 1e9+1

using namespace std;

int N, M;
int A, B, C;
int ARR[MAX];
int SEG[MAX*4];

int seg_init(int n, int s, int e) {
  if(s==e) return SEG[n] = ARR[s];
  int m = (s+e)>>1;
  return SEG[n] = min(seg_init(n*2, s, m), seg_init(n*2+1, m+1, e));
}

int seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s == e) return SEG[n] = a;
  
  int m = (s+e)>>1;
  return SEG[n] = min(seg_update(n*2, s, m, i, a), seg_update(n*2+1, m+1, e, i, a));
}

int seg_query(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return INF;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return min(seg_query(n*2, s, m, l, r), seg_query(n*2+1, m+1, e, l, r));
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }
  seg_init(1, 1, N);
  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A >> B >> C;
    if(A==1) {
      seg_update(1, 1, N, B, C);
    } else {
      cout << seg_query(1, 1, N, B, C) << "\n";
    }
  }

  return 0;
}