#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX INT32_MAX

int N;
int W[10001];
int u, v;
vector<int> E[10001];
int visit[10001], DP[10001][2];

void DFS(int p) {
  visit[p] = 1;
  DP[p][0] = 0;
  DP[p][1] = W[p];

  for(int i = 0; i < E[p].size(); i++) {
    int a = E[p][i];
    
    if(visit[a]) continue;

    DFS(a);

    DP[p][0] += max(DP[a][0], DP[a][1]);
    DP[p][1] += DP[a][0];
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> W[i];
  }
  for(int i = 1; i <= N-1; i++) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  DFS(1);

  cout << max(DP[1][0], DP[1][1]) << "\n";

  return 0;
}