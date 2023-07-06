#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF INT32_MAX

using namespace std;

int N, M;
int A, B, C;
vector<pair<pair<int, int>, int>> E;
long long Dist[501];
int BF;

void F() {
  for(int i = 0; i <= N; i++) {
    Dist[i] = INF;
  }

  Dist[1] = 0;

  for(int i = 1; i <= N; i++) {
    for(int j = 0; j < E.size(); j++) {
      int V1 = E[j].first.first;
      int V2 = E[j].first.second;
      int C = E[j].second;

      if(Dist[V1] == INF) continue;
      if(Dist[V2] > Dist[V1] + C) {
        if(i == N) {
          BF = 1;
          return;
        } else {
          Dist[V2] = Dist[V1] + C;
        }
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> A >> B >> C;
    E.push_back({{A, B}, C});
  }
  F();
  if(BF) {
    cout << -1;
  } else {
    for(int i = 2; i <= N; i++) {
      if(Dist[i] == INF) cout << -1 << "\n";
      else cout << Dist[i] << "\n";
    }
  }

  return 0;
}