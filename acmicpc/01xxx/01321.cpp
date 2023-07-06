#include <iostream>
#include <algorithm>

#define MAX 500001

using namespace std;

int N, M;
int Q, A, B;
int ARR[MAX];
int SEG[MAX*4];

int seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] += a;

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i, a) + seg_update(n*2+1, m+1, e, i, a);
}

int seg_query(int n, int s, int e, int a) {
  if(s==e) return s;

  int m = (s+e)>>1;
  if(a <= SEG[n*2]) return seg_query(n*2, s, m, a);
  else return seg_query(n*2+1, m+1, e, a-SEG[n*2]);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
    seg_update(1, 1, N, i, ARR[i]);
  }

  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> Q;
    if(Q==1) {
      cin >> A >> B;
      seg_update(1, 1, N, A, B);
    } else {
      cin >> A;
      cout << seg_query(1, 1, N, A) << "\n";
    }
  }

  return 0;
}