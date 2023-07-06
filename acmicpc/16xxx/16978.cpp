#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100001

using namespace std;
using LL = long long;
using PII = pair<int, int>;

typedef struct {
  int i, n, l, r;
  LL res;
} QQ;

int N;
int M;
int Q, A, B, C;
int ARR[MAX];
LL SEG[MAX*4];
vector<PII> Q1;
vector<QQ> Q2;

LL seg_update(int n, int s, int e, int i, int a) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] = a;

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i, a) + seg_update(n*2+1, m+1, e, i, a);
}

LL seg_query(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[n];
  
  int m = (s+e)>>1;
  return seg_query(n*2, s, m, l, r) + seg_query(n*2+1, m+1, e, l, r);
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
  Q1.push_back({0, 0});
  for(int i = 1; i <= M; i++) {
    cin >> Q;
    if(Q == 1) {
      cin >> A >> B;
      Q1.push_back({A, B});
    } else {
      cin >> A >> B >> C;
      Q2.push_back({i, A, B, C});
    }
  }

  sort(Q2.begin(), Q2.end(), [](QQ a, QQ b) {
    return a.n < b.n;
  });

  int idx = 0;
  for(int i = 0; i < Q1.size(); i++) {
    seg_update(1, 1, N, Q1[i].first, Q1[i].second);
    while(idx < Q2.size()) {
      if(Q2[idx].n > i) break;
      Q2[idx].res = seg_query(1, 1, N, Q2[idx].l, Q2[idx].r);
      idx++;
    }
  }

  sort(Q2.begin(), Q2.end(), [](QQ a, QQ b) {
    return a.i < b.i;
  });

  for(auto a : Q2) {
    cout << a.res << "\n";
  }

  return 0;
}