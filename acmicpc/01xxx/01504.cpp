#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <cstring>

#define MAX 1e9

using namespace std;

int N, E;
int u, v, w;
int v1, v2;
list<pair<int, int>> e[20001];
int D[20001];
int res;

void F(int S) {
  priority_queue<pair<int, int>> PQ;

  for(int i = 0; i <= N; i++) {
    D[i] = MAX;
  }

  PQ.push(make_pair(0, S));
  D[S] = 0;

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

  cin >> N >> E;

  for(int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    e[u].push_back(make_pair(v, w));
    e[v].push_back(make_pair(u, w));
  }

  cin >> v1 >> v2;

  F(1);
  int R1 = D[v1];
  int R2 = D[v2];

  F(v2);
  R1 += D[N];

  F(v1);
  R2 += D[N];

  res = min(R1+D[v2], R2 + D[v2]);

  if(D[v2] == MAX || res >= MAX) cout << -1;
  else cout << res;
  
  return 0;
}