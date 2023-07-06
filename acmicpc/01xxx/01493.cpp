#include <iostream>
#include <algorithm>

#define MAX 20
#define INF 1e18+1

using namespace std;
using LL = long long;

typedef struct {
  int i, n;
} Cube;

int L, W, H;
int N;
int I;
Cube A[MAX];
LL R = INF;

LL F(int l, int w, int h, int n) {
  if(!l || !w || !h) return 0;
  int mn = min(l, min(w, h));
  int c = 1 << n;
  while(c > mn || A[n].n == 0) {
    n--;
    c >>= 1;
  }
  if(n < 0) return -1;

  A[n].n--;

  int r1 = F(l, w, h-c, n);
  int r2 = F(l, w-c, c, n);
  int r3 = F(l-c, c, c, n);
  
  if(r1 < 0 || r2 < 0 || r3 < 0) return -1;
  else return 1 + r1 + r2 + r3;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> L >> W >> H;
  cin >> N;
  for(int i = 0; i < MAX; i++) {
    A[i].i = i;
  }
  for(int i = 0; i < N; i++) {
    cin >> I;
    cin >> A[I].n;
  }

  cout << F(L, W, H, MAX-1);

  return 0;
}