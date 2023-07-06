#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define INF 1e9

typedef long long LL;

using namespace std;

int N;
int A[MAX];
int M;
int a, b, c;
int T[MAX*4];

int init(int n, int s, int e) {
  if(s==e) return T[n] = s;
  int m = (s+e)/2;
  int i1 = init(n*2, s, m);
  int i2 = init(n*2+1, m+1, e);
  if(A[i1] <= A[i2]) return T[n] = i1;
  else return T[n] = i2;
}

int update(int n, int s, int e, int i) {
  if(i < s || i > e) return T[n];
  if(s == e) {
    if(i == s) {
      T[n] = i;
    }
    return T[n];
  }
  int m = (s+e)/2;
  int u1 = update(n*2, s, m, i);
  int u2 = update(n*2+1, m+1, e, i);
  if(A[u1] <= A[u2]) return T[n] = u1;
  else return T[n] = u2;
}

int get(int n, int s, int e, int l, int r) {
  if(l > e || r < s) return -1;
  if(l <= s && e <= r) return T[n];
  int m = (s+e)/2;

  int g1 = get(n*2, s, m, l, r);
  int g2 = get(n*2+1, m+1, e, l, r);
  if(g2 == -1 || (g1 != -1 && A[g1] <= A[g2])) return g1;
  else return g2;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  init(1, 0, N-1);

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    if(a == 1) {
      A[b-1] = c;
      update(1, 0, N-1, b-1);
    } else {
      cout << get(1, 0, N-1, b-1, c-1)+1 << "\n";
    }
  }

  return 0;
}