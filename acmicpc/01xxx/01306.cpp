#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

int N, M;
int ARR[MAX];
int SEG[MAX*4];

int seg_init(int n, int s, int e) {
  if(s==e) return SEG[n] = ARR[s];

  int m = (s+e)>>1;
  return SEG[n] = max(seg_init(n*2, s, m), seg_init(n*2+1, m+1, e));
}

int seg_query(int n, int s, int e, int l, int r) {
  if(r < s || e < l) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return max(seg_query(n*2, s, m, l, r), seg_query(n*2+1, m+1, e, l, r));
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }
  seg_init(1, 1, N);

  for(int i = M; i <= N-M+1; i++) {
    cout << seg_query(1, 1, N, i-M+1, i+M-1) << " ";
  }

  return 0;
}