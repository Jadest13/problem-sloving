#include <bits/stdc++.h>

#define MAX 301

using namespace std;
using PII = pair<int, int>;

int N, M, K;
int u, v, w;
int W[MAX][MAX];
vector<PII> E[MAX];
int DP[MAX][MAX];

int F(int n, int p, int w) {
  if(n >= M) return 0;
  if(p == 1) return w;

  
  
  for(auto a : E[p]) {
    DP[n][p] = max(DP[n][p], F(n+1, a.first, w + a.second));
  }
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(DP, -1, sizeof(DP));

  cin >> N >> M >> K;
  for(int i = 1; i <= K; i++) {
    cin >> u >> v >> w;
    W[u][v] = max(W[u][v], w);
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(W[i][j]) E[j].push_back({i, W[i][j]});
    }
  }

  cout << F(0, N, 0);
  



  return 0;
}