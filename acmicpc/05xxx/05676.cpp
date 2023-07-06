#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, K;
char A;
int B, C;
int ARR[MAX];
int SEG[MAX*4];

int seg_init(int n, int s, int e){
  if(s==e) return SEG[n] = ARR[s];
  int m = (s+e)>>1;
  return SEG[n] = seg_init(n*2, s, m) * seg_init(n*2+1, m+1, e);
}

int seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] = a;
  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i, a) * seg_update(n*2+1, m+1, e, i, a);
}

int seg_query(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 1;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return seg_query(n*2, s, m, l, r) * seg_query(n*2+1, m+1, e, l, r);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while(cin >> N >> K) {
    for(int i = 1; i <= N; i++) {
      cin >> ARR[i];
      ARR[i] = (ARR[i]>0)?1:(ARR[i]<0)?-1:0;
    }
    seg_init(1, 1, N);
    for(int i = 1; i <= K; i++) {
      cin >> A >> B >> C;
      if(A == 'C') {
        C = (C>0)?1:(C<0)?-1:0;
        seg_update(1, 1, N, B, C);
      } else {
        int ret = seg_query(1, 1, N, B, C);
        cout << ((ret>0)?'+':(ret<0)?'-':'0');
      }
    }
    cout << "\n";
  }

  return 0;
}