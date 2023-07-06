#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX INT32_MAX

using namespace std;

int N, M, X;
int u, v, w;
vector<pair<int, int>> E[1001];
int Dist[1001];
int Cost = 0;

int F(int s, int e) {
  if(s==e) return 0;
  priority_queue<pair<int, int>> PQ;
  for(int i = 0; i <= N; i++) {
    Dist[i] = MAX;
  }

  PQ.push({0, s});

  while(!PQ.empty()) {
    int now_W = -PQ.top().first;
    int now_P = PQ.top().second;
    PQ.pop();

    if(now_P == e) {
      break;
    }

    for(auto a : E[now_P]) {
      int next_P = a.first;
      int next_W = a.second;

      if(Dist[next_P] > now_W + next_W) {
        Dist[next_P] = now_W + next_W;
        PQ.push({-Dist[next_P], next_P});
      }
    }
  }
  return Dist[e];
}

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> X;
  for(int i = 1; i <= M; i++) {
    cin >> u >> v >> w;
    E[u].push_back({v, w});
  }

  for(int i = 1; i <= N; i++) {
    int c = F(i, X) + F(X, i);
    Cost = max(Cost, c);
  }

  cout << Cost;

  exit(0);
}