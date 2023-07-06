#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define LL long long

using namespace std;

int N;
int M;
int ARR[MAX];
LL SEG[MAX*4];
int A, B, C, D;

void seg_add(int n, int s, int e, int l, int r, int k) {
  if(l > e || r < s) return;
  if(l <= s && e <= r) {
    SEG[n] += k;
    return;
  }
  
  int m = (s+e)/2;
  seg_add(n*2, s, m, l, r, k);
  seg_add(n*2+1, m+1, e, l, r, k);
}

LL seg_get(int n, int s, int e, int x) {
  LL ret = 0;
  if(x < s || e < x) return 0;
  if(s <= x && x <= e) ret += SEG[n];
  if(s==e) return ret;
  
  int m = (s+e)/2;
  return ret + seg_get(n*2, s, m, x) + seg_get(n*2+1, m+1, e, x);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> ARR[i];
  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> A;
    if(A == 1) {
      cin >> B >> C >> D;
      seg_add(1, 0, N-1, B-1, C-1, D);
    } else {
      cin >> B;
      cout << ARR[B-1] + seg_get(1, 0, N-1, B-1) << "\n";
    }
  }
}