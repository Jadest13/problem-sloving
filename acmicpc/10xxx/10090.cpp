#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000001
#define LL long long

using namespace std;

int N;
int ARR[MAX];
int SEG[MAX*4];
LL R;

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
  for(int i = N; i >= 1; i--) {
    cin >> ARR[i];
  }
  for(int i = 1; i <= N; i++) {
    R += seg_query(1, 1, N, 1, ARR[i]-1);
    seg_update(1, 1, N, ARR[i], 1);
  }

  cout << R;

  return 0;
}