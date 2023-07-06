#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N;
int A;
int ARR[MAX];
int SEG[MAX*4];

int segInit(int n, int s, int e) {
  if(s==e) return SEG[n] = 1;

  int m = (s+e)>>1;
  return SEG[n] = segInit(n*2, s, m) + segInit(n*2+1, m+1, e);
}

int segUpdate(int n, int s, int e, int i) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] = 0;

  int m = (s+e)>>1;
  return SEG[n] = segUpdate(n*2, s, m, i) + segUpdate(n*2+1, m+1, e, i);
}

int segQuery(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return segQuery(n*2, s, m, l, r) + segQuery(n*2+1, m+1, e, l, r);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A;
    ARR[A] = i;
  }
  segInit(1, 1, N);
  for(int i = 1; i <= N; i++) {
    if(i%2) {
      cout << segQuery(1, 1, N, 1, ARR[(i+1)/2]-1) << "\n";
      segUpdate(1, 1, N, ARR[(i+1)/2]);
    } else {
      cout << segQuery(1, 1, N, ARR[N-(i+1)/2+1]+1, N) << "\n";
      segUpdate(1, 1, N, ARR[N-(i+1)/2+1]);
    }
  }

  return 0;
}