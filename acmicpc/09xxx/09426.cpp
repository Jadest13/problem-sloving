#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 250001
#define SZ 65536
#define LL long long

using namespace std;

int N, K;
int ARR[MAX];
int SEG[SZ*4];
int L, R;
LL res;

int seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] += a;

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i, a) + seg_update(n*2+1, m+1, e, i, a);
}

int seg_query(int n, int s, int e, int i) {
  if(s == e) return s;

  int m = (s+e)>>1;
  if(SEG[n*2] >= i) {
    return seg_query(n*2, s, m, i);
  } else {
    return seg_query(n*2+1, m+1, e, i-SEG[n*2]); 
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  int mid = (K+1)/2;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }

  L = R = 1;
  while(R < K) {
    seg_update(1, 0, SZ, ARR[R++], 1);
  }

  while(R <= N) {
    seg_update(1, 0, SZ, ARR[R++], 1);
    res += seg_query(1, 0, SZ, mid);
    seg_update(1, 0, SZ, ARR[L++], -1);
  }
  cout << res;

  return 0;
}