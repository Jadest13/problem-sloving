#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, K;
int A[10];
int SEG[MAX*4];
int idx;

int init(int n, int s, int e) {
  if(s==e) return SEG[n] = 1;
  int m = (s+e)/2;
  return SEG[n] = init(n*2, s, m) + init(n*2+1, m+1, e);
}

int get(int n, int s, int e, int a) {
  SEG[n]--;
  if(s==e) return s;

  int m = (s+e)/2;
  if(a <= SEG[n*2]) return get(n*2, s, m, a);
  else return get(n*2+1, m+1, e, a-SEG[n*2]);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  init(1, 1, N);

  cout << "<";
  idx = 1;
  for(int i = 1; i <= N; i++) {
    idx += K-1;
    if(idx%SEG[1]) idx %= SEG[1];
    else idx = SEG[1];
    cout << get(1, 1, N, idx) << (i!=N?", ":">");
  }
}