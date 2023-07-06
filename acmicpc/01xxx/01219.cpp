#include <bits/stdc++.h>

#define MAX 50
#define INF 1e9

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int N, s, e, M;
int u, v, w;
vector<PII> E[MAX];
int W[MAX];
LL Dist[MAX];
int loop;

int BFS(int s, int e) {
  if(s==e) return 1;
  int visit[MAX] = {0};
  queue<int> Q;
  Q.push(s);
  visit[s] = 1;
  while(!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for(auto a : E[cur]) {
      int np = a.first;
      if(visit[np]) continue;
      visit[np] = 1;
      if(np == e) return 1;
      Q.push(np);
    }
  }
  return 0;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(Dist, Dist+MAX, -INF);
  cin >> N >> s >> e >> M;
  for(int i = 1; i <= M; i++) {
    cin >> u >> v >> w;
    E[u].push_back({v, w});
  }
  for(int i = 0; i < N; i++) {
    cin >> W[i];
  }

  Dist[s] = W[s];
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      for(auto a : E[j]) {
        int np = a.first;
        LL nc = a.second;

        if(Dist[j] == -INF) continue;
        if(Dist[j] - nc + W[np] > Dist[np]) {
          Dist[np] = Dist[j] - nc + W[np];
          if(i == N-1) {
            if(BFS(np, e)) {
              loop = 1;
            }
          }
        }
      }
    }
  }

  if(Dist[e] == -INF) {
    cout << "gg";
  } else if(loop) {
    cout << "Gee";
  } else {
    cout << Dist[e];
  }

  return 0;
}