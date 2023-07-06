#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define INF 1e9
#define PII pair<int, int>

typedef long long LL;

using namespace std;

int T;
int N, K;
int Q, A, B;
int ARR[MAX];
PII ST[MAX*4];

PII init(int n, int s, int e) {
  if(s==e) return ST[n] = {ARR[s], ARR[s]};
  int m = (s+e)/2;
  PII i1 = init(n*2, s, m);
  PII i2 = init(n*2+1, m+1, e);
  return ST[n] = {min(i1.first, i2.first), max(i1.second, i2.second)};
}

PII update(int n, int s, int e, int a, int b) {
  if((a < s || a > e) && (b < s || b > e)) return ST[n];
  if(s==e) {
    if(s == a) ST[n] = {ARR[a], ARR[a]};
    if(s == b) ST[n] = {ARR[b], ARR[b]};
    return ST[n];
  }
  int m = (s+e)/2;
  PII u1 = update(n*2, s, m, a, b);
  PII u2 = update(n*2+1, m+1, e, a, b);
  return ST[n] = {min(u1.first, u2.first), max(u1.second, u2.second)};
}

int check(int n, int s, int e, int l, int r) {
  if(l > e || r < s) return 1;
  if(l <= s && e <= r) return (ST[n].first >= l && ST[n].second <= r);
  int m = (s+e)/2;

  return (check(n*2, s, m, l, r) && check(n*2+1, m+1, e, l, r));
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
      ARR[i] = i;
    }
    init(1, 0, N-1);

    for(int i = 0; i < K; i++) {
      cin >> Q >> A >> B;

      if(!Q) {
        int tmp = ARR[A];
        ARR[A] = ARR[B];
        ARR[B] = tmp;
        update(1, 0, N-1, A, B);
      } else {
        cout << (check(1, 0, N-1, A, B)?"YES":"NO") << "\n";
      }
    }
  }

  return 0;
}