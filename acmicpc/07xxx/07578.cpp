#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001
#define LL long long

using namespace std;

int N;
int tmp;
int A1[MAX], A2[MAX*2];
LL SEG[MAX*4];
LL R;

LL seg_get(int n, int s, int e, int l, int r) {
  if(r < s || e < l) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return seg_get(n*2, s, m, l, r) + seg_get(n*2+1, m+1, e, l, r);
}

void seg_update(int n, int s, int e, int i) {
  if(i < s || e < i) return;
  SEG[n]++;
  if(s==e) return;

  int m = (s+e)>>1;
  seg_update(n*2, s, m, i);
  seg_update(n*2+1, m+1, e, i);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A1[i];
  }
  for(int i = 1; i <= N; i++) {
    cin >> tmp;
    A2[tmp] = i;
  }

  for(int i = 1; i <= N; i++) {
    LL sum = seg_get(1, 1, N, A2[A1[i]]+1, N);
    R += sum;
    seg_update(1, 1, N, A2[A1[i]]);
  }

  cout << R;

  return 0;
}