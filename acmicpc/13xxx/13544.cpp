#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001

using namespace std;

int N, M;
int A, B, C;
int ARR[MAX];
vector<int> SEG[MAX*4];
int last_ans = 0;

void merge(int n, int s, int e) {
  int m = (s+e)/2;
  int l = s, r = m+1;
  if(s==e) {
    SEG[n] = {ARR[s]};
    return;
  }

  merge(n*2, s, m);
  merge(n*2+1, m+1, e);

  while(l <= m && r <= e) {
    if(ARR[l] <= ARR[r]) {
      SEG[n].push_back(ARR[l++]);
    } else {
      SEG[n].push_back(ARR[r++]);
    }
  }

  while(l <= m) SEG[n].push_back(ARR[l++]);
  while(r <= e) SEG[n].push_back(ARR[r++]);

  for(int i = s; i <= e; i++) {
    ARR[i] = SEG[n][i-s];
  }
}

int get(int n, int s, int e, int l, int r, int k) {
  if(l > e || r < s) return 0;
  if(l <= s && e <= r) return SEG[n].end() - upper_bound(SEG[n].begin(), SEG[n].end(), k);
  int m = (s+e)/2;
  if(m < l) return get(n*2+1, m+1, e, l, r, k);
  if(m+1 > r) return get(n*2, s, m, l, r, k);
  return get(n*2, s, m, l, r, k) + get(n*2+1, m+1, e, l, r, k);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 0; i < N; i++) cin >> ARR[i];
  merge(1, 0, N-1);

  cin >> M;
  for(int i = 0; i < M; i++) {
    cin >> A >> B >> C;
    last_ans = get(1, 0, N-1, (A^last_ans)-1, (B^last_ans)-1, (C^last_ans));
    cout << last_ans << "\n";
  }
}