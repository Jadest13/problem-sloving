#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define LL long long

using namespace std;

int N, Q;
int X, Y, A, B;
int ARR[MAX];
LL SEG[MAX*4];

LL init(int n, int s, int e) {
  if(s==e) return SEG[n] = ARR[s];
  int m = (s+e)>>1;
  return SEG[n] = init(n*2, s, m) + init(n*2+1, m+1, e);
}

LL get(int n, int s, int e, int l, int r) {
  if(r < s || e < l) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return get(n*2, s, m, l, r) + get(n*2+1, m+1, e, l, r);
}

LL update(int n, int s, int e, int a, int b) {
  if(s==e) {
    if(s==a) SEG[n] = b;
    return SEG[n];
  }
  if(a < s || e < a) return SEG[n];

  int m = (s+e)>>1;
  return SEG[n] = update(n*2, s, m, a, b) + update(n*2+1, m+1, e, a, b);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> Q;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
  }

  init(1, 1, N);

  for(int i = 1; i <= Q; i++) {
    cin >> X >> Y >> A >> B;
    if(X > Y) {
      int tmp = X;
      X = Y;
      Y = tmp;
    }
    cout << get(1, 1, N, X, Y) << "\n";
    update(1, 1, N, A, B);
  }

  return 0;
}