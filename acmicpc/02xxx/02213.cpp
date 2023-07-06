#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define MAX INT32_MAX

int n;
int W[10001];
int u, v;
vector<int> E[10001];
vector<int> res;
int visit[10001], DP[10001][2];

void F(int p, int q) {
  
  if(DP[p][1] > DP[p][0] && !visit[q]) {
    res.push_back(p);
    visit[p] = 1;
  }

  for(int i = 0; i < E[p].size(); i++) {
    int a = E[p][i];
    
    if(a==q) continue;

    F(a, p);
  }
}

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

  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> W[i];
  }
  for(int i = 1; i <= n-1; i++) {
    cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  DFS(1);

  memset(visit, 0, sizeof(visit));
  F(1, 0);
  sort(res.begin(), res.end());

  cout << max(DP[1][0], DP[1][1]) << "\n";
  for(auto a : res) {
    cout << a << " ";
  }

  return 0;
}