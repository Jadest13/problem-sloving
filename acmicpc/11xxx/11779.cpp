#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define MAX INT32_MAX

using namespace std;

int n, m;
int u, v, w;
int s, e;
vector<pair<int, int>> E[1001];
int D[1001];
int R[1001];
vector<int> RV;

void Dijk() {
  priority_queue<pair<int, int>> PQ;
  PQ.push({0, s});
  D[s] = 0;

  while(!PQ.empty()) {
    int pd = -PQ.top().first;
    int pn = PQ.top().second;
    PQ.pop();

    if(pd > D[pn]) continue;

    for(auto a : E[pn]) {
      int nn = a.first;
      int nd = pd + a.second;

      if(nd < D[nn]) {
        D[nn] = nd;
        R[nn] = pn;
        PQ.push({-nd, nn});
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    E[u].push_back({v, w});
  }
  cin >> s >> e;

  for(int i = 0; i <= n; i++) {
    D[i] = MAX;
  }

  Dijk();
  cout << D[e] << "\n";

  while(e) {
    RV.push_back(e);
    e = R[e];
  }

  cout << RV.size() << "\n";
  for(int i = RV.size()-1; i >= 0; i--) {
    cout << RV[i] << " ";
  }
  
  return 0;
}