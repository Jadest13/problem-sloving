#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX INT32_MAX

using namespace std;

int N, M, K;
int S, D;
int a, b, w;
int p;
int P;
vector<pair<int, int>> E[1001];
long Dist[1001][1001];

long min(long a, long b) {
  return ((a<b)?a:b);
}

void F(int s, int e) {
  priority_queue<pair<int, pair<int, int>>> PQ;

  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
      Dist[i][j] = MAX;
    }
  }

  Dist[s][0] = 0;
  PQ.push({0, {s, 0}});

  while(!PQ.empty()) {
    int now_W = -PQ.top().first;
    int now_P = PQ.top().second.first;
    int now_D = PQ.top().second.second;
    PQ.pop();

    if(now_D == N) continue;

    if(Dist[now_P][now_D] < now_W) {
      continue;
    }

    for(auto a : E[now_P]) {
      int next_P = a.first;
      int next_W = a.second + now_W;

      if(Dist[next_P][now_D+1] > next_W) {
        Dist[next_P][now_D+1] = next_W;
        PQ.push({-next_W, {next_P, now_D+1}});
      }
    }
  }
}

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M >> K;
  cin >> S >> D;
  for(int i = 1; i <= M; i++) {
    cin >> a >> b >> w;
    E[a].push_back({b, w});
    E[b].push_back({a, w});
  }

  F(S, D);

  long m = MAX;
  for(int i = 1; i < N; i++) {
    Dist[D][i] += i * p;
    m = min(Dist[D][i], m);
  }
  cout << m << "\n";

  for(int i = 1; i <= K; i++) {
    m = MAX;
    cin >> p;
    for(int i = 1; i < N; i++) {
      Dist[D][i] += i * p;
      m = min(Dist[D][i], m);
    }
    cout << m << "\n";
  }

  exit(0);
}