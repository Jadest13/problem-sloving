#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001

using namespace std;

typedef struct {
  int x, y, z;
} Grade;

int N;
int a;
Grade ARR[MAX];
int SEG[MAX*4];
int R;

int seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] = a;

  int m = (s+e)>>1;
  return SEG[n] = min(seg_update(n*2, s, m, i, a), seg_update(n*2+1, m+1, e, i, a));
}

int seg_query(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return MAX;
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
    cin >> a;
    ARR[a].x = i;
  }
  for(int i = 1; i <= N; i++) {
    cin >> a;
    ARR[a].y = i;
  }
  for(int i = 1; i <= N; i++) {
    cin >> a;
    ARR[a].z = i;
  }

  sort(ARR+1, ARR+N+1, [](Grade a, Grade b) {
    return a.x < b.x;
  });
  for(int i = 1; i <= N; i++) {
    seg_update(1, 1, N, i, MAX);
  }
  for(int i = 1; i <= N; i++) {
    if(seg_query(1, 1, N, 1, ARR[i].y) > ARR[i].z) R++;
    seg_update(1, 1, N, ARR[i].y, ARR[i].z);
  }
  
  cout << R;

  return 0;
}