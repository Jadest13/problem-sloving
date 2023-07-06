#include <bits/stdc++.h>

#define MAX 801
#define INF 1e9
#define OUT 400

using namespace std;

int N, P;
int parent[MAX];
vector<int> E[MAX];
int capacity[MAX][MAX], flow[MAX][MAX];
int S, T;
int R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> P;
  for(int i = 1; i <= N; i++) {
    E[i].push_back(i+OUT);
    E[i+OUT].push_back(i);

    capacity[i][i+OUT] = 1;
  }

  for(int i = 1; i <= P; i++) {
    int u, v;
    cin >> u >> v;
    E[u].push_back(v+OUT);
    E[v].push_back(u+OUT);

    E[u+OUT].push_back(v);
    E[v+OUT].push_back(u);

    capacity[u+OUT][v] = 1;
    capacity[v+OUT][u] = 1;
  }

  S = 1+OUT;
  T = 2;

  while(1) {
    fill(parent+1, parent+N+OUT+1, -1);

    queue<int> Q;
    Q.push(S);
    while(!Q.empty()) {
      int p = Q.front();
      Q.pop();

      for(auto a : E[p]) {
        if(capacity[p][a] - flow[p][a] <= 0 || parent[a] != -1) continue;
        Q.push(a);
        parent[a] = p;
        if(a == T) break;
      }
    }

    if(parent[T] == -1) break;

    int ret = INF;
    for(int i = T; i != S; i = parent[i]) {
      ret = min(capacity[parent[i]][i] - flow[parent[i]][i], ret);
    }

    for(int i = T; i != S; i = parent[i]) {
      flow[parent[i]][i] += ret;
      flow[i][parent[i]] -= ret;
    }

    R += ret;
  }

  cout << R;

  return 0;
}