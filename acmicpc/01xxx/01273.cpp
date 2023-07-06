#include <iostream>
#include <algorithm>

#define MAX 300001
#define SMX 3000001

using namespace std;

int N;
int C;
int H[MAX];
int V[SMX];
int D[3] = {1, 2, 5};
int M;
int A;
int hM;
int R;
int SEG[SMX*4];

int seg_init(int n, int s, int e) {
  if(s == e) return SEG[n] = 1;

  int m = (s+e)>>1;
  return SEG[n] = seg_init(n*2, s, m) + seg_init(n*2+1, m+1, e);
}

int seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] = a;

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i, a) + seg_update(n*2+1, m+1, e, i, a);
}

int seg_query(int n, int s, int e, int a) {
  if(s==e) return s;

  int m = (s+e)>>1;
  if(SEG[n*2] < a) return seg_query(n*2+1, m+1, e, a-SEG[n*2]);
  else return seg_query(n*2, s, m, a);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < 3; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> C;
      V[H[j]] += D[i];
      V[H[j]+C] -= D[i];
      H[j] += C;
      hM = max(hM, H[j]);
    }
  }
  
  for(int i = 1; i <= hM; i++) {
    V[i] += V[i-1];
  }

  seg_init(1, 1, SMX);

  cin >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A;
    int idx = seg_query(1, 1, SMX, A);
    cout << V[idx-1] << "\n";
    seg_update(1, 1, SMX, idx, 0);
  }

  return 0;
}