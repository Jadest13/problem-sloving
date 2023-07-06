#include <bits/stdc++.h>

#define MAX 1001

using namespace std;
using PII = pair<int, int>;

int N;
int A, B;
vector<PII> V;
vector<int> ans, idx;
vector<int> R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A >> B;
    V.push_back({A, B});
  }
  sort(V.begin(), V.end());

  for(int i = 0; i < V.size(); i++) {
    if(i==0) {
      ans.push_back(V[i].second);
      idx.push_back(0);
      continue;
    }
    if(ans.back() < V[i].second) {
      ans.push_back(V[i].second);
      idx.push_back(ans.size()-1);
    } else {
      int l = 0;
      int r = ans.size() - 1;
      while(l < r) {
        int m = (l+r)>>1;
        if(ans[m] < V[i].second) {
          l = m+1;
        } else {
          r = m;
        }
      }
      ans[l] = V[i].second;
      idx.push_back(l);
    }
  }

  cout << V.size() - ans.size() << "\n";

  int now = ans.size()-1;
  for(int i = idx.size()-1; i >= 0; i--) {
    if(now == idx[i]) {
      now--;
    } else {
      R.push_back(V[i].first);
    }
  }
  sort(R.begin(), R.end());
  for(auto a : R) {
    cout << a << "\n";
  }

  return 0;
}