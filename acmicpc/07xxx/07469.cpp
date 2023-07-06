#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define VI vector<int>

using namespace std;

int N, M;
int A, B, C;
int ARR[MAX];
VI SEG[MAX*4];

VI seg_init(int n, int s, int e) {
  if(s==e) return SEG[n] = {ARR[s]};

  int m = (s+e)>>1;
  VI i1 = seg_init(n*2, s, m);
  VI i2 = seg_init(n*2+1, m+1, e);

  int l = 0, r = 0;
  while(l < i1.size() && r < i2.size()) {
    if(i1[l] <= i2[r]) SEG[n].push_back(i1[l++]);
    else SEG[n].push_back(i2[r++]);
  }
  while(l < i1.size()) SEG[n].push_back(i1[l++]);
  while(r < i2.size()) SEG[n].push_back(i2[r++]);
  
  return SEG[n];
}

int seg_query(int n, int s, int e, int l, int r, int a) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return upper_bound(SEG[n].begin(), SEG[n].end(), a) - SEG[n].begin();
  
  int m = (s+e)>>1;
  return seg_query(n*2, s, m, l, r, a) + seg_query(n*2+1, m+1, e, l, r, a);
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

  for(int i = 1; i <= M; i++) {
    cin >> A >> B >> C;
    int l = -1e9, r = 1e9;
    while(l <= r) {
      int m = (l+r)>>1;
      if(seg_query(1, 1, N, A, B, m) < C) l = m+1;
      else r = m-1;
    }
    cout << l << "\n";
  }

  return 0;
}