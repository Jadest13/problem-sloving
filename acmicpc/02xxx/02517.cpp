#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9+1
#define MAX 500001
#define LL long long

using namespace std;

int N;
int A;
int ARR[MAX];
int SEG[MAX*4];
vector<int> V;

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
    V.push_back(ARR[i]);
  }
  sort(V.begin(), V.end());

  for(int i = 1; i <= N; i++) {
    int p = (lower_bound(V.begin(), V.end(), ARR[i]) - V.begin())+1;
    seg_update(1, 1, N, p, 1);
    cout << i - seg_query(1, 1, N, 0, p-1) << "\n";
  }

  return 0;
}