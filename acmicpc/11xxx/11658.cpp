#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1025

using namespace std;

int N, M;
int W, A, B, C, D;
int h = 1;
int ARR[MAX][MAX];
int SEG[MAX*4][MAX*4];

void seg_update(int x, int y, int a) {
  int i = y+h-1;
  int j = x+h-1;
  SEG[i][j] = a;

  while(j > 1) {
    j /= 2;
    SEG[i][j] = SEG[i][j*2] + SEG[i][j*2+1];
  }

  while(i > 1) {
    j = x+h-1;
    i /= 2;
    SEG[i][j] = SEG[i*2][j] + SEG[i*2+1][j];

    while(j > 1) {
      j /= 2;
      SEG[i][j] = SEG[i][j*2] + SEG[i][j*2+1];
    }
  }
}

int seg_query_col(int y, int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[y][n];
  int m = (s+e)>>1;
  return seg_query_col(y, n*2, s, m, l, r) + seg_query_col(y, n*2+1, m+1, e, l, r);
}

int seg_query_row(int n, int s, int e, int l, int r, int c1, int c2) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return seg_query_col(n, 1, 1, h, c1, c2);
  int m = (s+e)>>1;
  return seg_query_row(n*2, s, m, l, r, c1, c2) + seg_query_row(n*2+1, m+1, e, l, r, c1, c2);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  while(h < N) h <<= 1;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> ARR[i][j];
      seg_update(i, j, ARR[i][j]);
    }
  }
  
  for(int i = 0; i < M; i++) {
    cin >> W;
    if(!W) {
      cin >> A >> B >> C;
      seg_update(A, B, C);
    } else {
      cin >> A >> B >> C >> D;
      if(A > C) swap(A, C);
      if(B > D) swap(B, D);
      cout << seg_query_row(1, 1, h, B, D, A, C) << "\n";
    }
  }

  return 0;
}