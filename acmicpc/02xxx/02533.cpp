#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 1e9

int N;
int u, v;
vector<int> E[1000001];
int visit[1000001], DP[1000001][2];

void DFS(int p) {
  visit[p] = 1;

  DP[p][0] = 0;
  DP[p][1] = 1;

  for(int i = 0; i < E[p].size(); i++) {
    int np = E[p][i];

    if(visit[np]) continue;

    DFS(np);

    DP[p][0] += DP[np][1];
    DP[p][1] += min(DP[np][0], DP[np][1]);
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N-1; i++) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  DFS(1);

  cout << min(DP[1][0], DP[1][1]);

  return 0;
}