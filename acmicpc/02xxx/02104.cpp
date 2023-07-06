#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100001
#define INF 1000001
#define LL long long

using namespace std;

int N;
LL ARR[MAX], SUM[MAX];

LL F(int s, int e) {
  if(s==e) return ARR[s]*ARR[s];

  int m = (s+e)>>1;
  LL ret = max(F(s, m), F(m+1, e));

  int l = m, r = m+1;
  LL mn = min(ARR[l], ARR[r]);
  ret = max(ret, (ARR[l]+ARR[r])*mn);

  while(s < l || r < e) {
    if(r < e && (l == s || ARR[l-1] < ARR[r+1])) {
      mn = min(mn, ARR[++r]);
    } else {
      mn = min(mn, ARR[--l]);
    }
    ret = max(ret, (SUM[r]-SUM[l-1])*mn);
  }
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> ARR[i];
    SUM[i] = SUM[i-1] + ARR[i];
  }
  cout << F(1, N);

  return 0;
}