#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;
using PII = pair<int, int>;

int N;
int L, H, R;
vector<PII> V;
multiset<int> SET;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> L >> H >> R;
    V.push_back({L, H});
    V.push_back({R, -H});
  }

  sort(V.begin(), V.end(), [](PII a, PII b) {
    return a.first < b.first;
  });
  V.push_back({1000000001, 0});

  SET.insert(0);
  int x = V[0].first;
  int y = 0;
  for(int i = 0; i < N*2;) {
    while(x == V[i].first) {
      if(V[i].second > 0) SET.insert(V[i].second);
      else SET.erase(SET.find(-V[i].second));
      i++;
    }
    if(y != *SET.rbegin()) {
      y = *SET.rbegin();
      cout << x << " " << y << " ";
    }
    x = V[i].first;
  }

  return 0;
}