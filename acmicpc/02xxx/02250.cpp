#include <bits/stdc++.h>

#define MAX 10001

using namespace std;

typedef struct {
  int l, r;
  int h;
} Node;

int N;
int c, l, r;
int E[MAX];
int root = 1;
Node T[MAX];
int L[MAX], R[MAX];
int R1, R2;

int DFS(int p, int c, int h) {
  int pos;
  if(T[c].l == -1) {
    pos = p;
  } else {
    pos = DFS(p, T[c].l, h+1)+1;
  }
  L[h] = min(L[h], pos);
  R[h] = max(R[h], pos);
  if(T[c].r != -1) {
    pos = DFS(pos+1, T[c].r, h+1);
  }
  if(R2 <= R[h]-L[h]+1) {
    R1 = h;
    R2 = R[h]- L[h] + 1;
  }
  return pos;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    L[i] = MAX;
  }
  for(int i = 1; i <= N; i++) {
    cin >> c >> l >> r;
    E[l] = c;
    E[r] = c;
    T[c] = {l, r};
  }

  while(E[root] != 0) {
    root = E[root];
  }

  DFS(1, root, 1);

  cout << R1 << " " << R2;

  return 0;
}