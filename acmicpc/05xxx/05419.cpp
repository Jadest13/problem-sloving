#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MAX 75001
#define LL long long
#define PII pair<int, int>

using namespace std;

int T;
int N;
vector<PII> POS;
vector<int> SEG;

int seg_update(int n, int s, int e, int i) {
  if(i < s || e < i) return SEG[n];
  if(s==e) return SEG[n] += 1;

  int m = (s+e)>>1;
  return SEG[n] = seg_update(n*2, s, m, i) + seg_update(n*2+1, m+1, e, i);
}

int seg_query(int n, int s, int e, int l, int r) {
  if(e < l || r < s) return 0;
  if(l <= s && e <= r) return SEG[n];

  int m = (s+e)>>1;
  return seg_query(n*2, s, m, l, r) + seg_query(n*2+1, m+1, e, l, r);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    map<int, int> Y;
    int num = 0;
    LL R = 0;

    cin >> N;
    POS.clear();
    POS.resize(N);
    SEG.clear();
    SEG.resize(N*4);

    for(int i = 0; i < N; i++) {
      cin >> POS[i].first >> POS[i].second;
      Y[POS[i].second] = 1;
    }
    sort(POS.begin(), POS.end(), [](PII a, PII b) {
      if(a.first == b.first) return a.second > b.second;
      else return a.first < b.first;
    });

    for(auto a = Y.end(); a-- != Y.begin();) {
      a->second = num++;
    }
    for(auto &a : POS) {
      a.second = Y[a.second];
      R += seg_query(1, 0, N-1, 0, a.second);
      seg_update(1, 0, N-1, a.second);
    }
    
    cout << R << "\n";
  }

  return 0;
}