#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 2001

using namespace std;
using LL = long long;

int N, M;
int u, v;
vector<int> ARR[MAX];
LL SEG[MAX*4];
LL R;

LL seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] += a;

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i, a) + seg_update(n*2+1, m+1, e, i, a);
}

LL seg_query(int n, int s, int e, int l, int r) {
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
    cin >> u >> v;
    ARR[u].push_back(v);
  }

  for(int i = 1; i <= N; i++) {
    for(auto a : ARR[i]) {
      R += seg_query(1, 1, N, a+1, N);
    }
    for(auto a : ARR[i]) {
      seg_update(1, 1, N, a, 1);
    }
  }
  cout << R;

  return 0;
}