#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define PII pair<int, int>

using namespace std;

int N, M;
int A, B, C;
int ARR[MAX];
PII SEG[MAX*4];

PII seg_init(int n, int s, int e) {
  if(s == e) return SEG[n] = {s, ARR[s]};

  int m = (s+e)>>1;
  PII i1 = seg_init(n*2, s, m);
  PII i2 = seg_init(n*2+1, m+1, e);
  return SEG[n] = ((i1.second <= i2.second)?i1:i2);
}

PII seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s == e) return SEG[n] = {s, a};

  int m = (s+e)>>1;
  PII i1 = seg_update(n*2, s, m, i, a);
  PII i2 = seg_update(n*2+1, m+1, e, i, a);
  return SEG[n] = ((i1.second <= i2.second)?i1:i2);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }
  seg_init(1, 1, N);

  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A;
    if(A==1) {
      cin >> B >> C;
      seg_update(1, 1, N, B, C);
    } else {
      cout << SEG[1].first << "\n";
    }
  }
  return 0;
}