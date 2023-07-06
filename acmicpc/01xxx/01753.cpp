#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

int V, E, K;
int u, v, w;
list<pair<int, int>> e[20001];
priority_queue<pair<int, int>> PQ;
int D[20001];

void F(int k) {
  PQ.push(make_pair(0, k));
  D[k] = 0;

  while(!PQ.empty()) {
    int pc = -PQ.top().first;
    int pp = PQ.top().second;
    PQ.pop();

    for(auto a : e[pp]) {
      int np = a.first;
      int nw = a.second;

      if(D[np] > pc + nw) {
        D[np] = pc + nw;
        PQ.push(make_pair(-D[np], np));
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> V >> E >> K;

  for(int i = 0; i <= V; i++) {
    D[i] = INT32_MAX;
  }

  for(int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    e[u].push_back(make_pair(v, w));
  }

  F(K);
  
  for(int i = 1; i <= V; i++) {
    if(D[i] == INT32_MAX) {
      cout << "INF\n";
    } else {
      cout << D[i] << "\n";
    }
  }

  return 0;
}