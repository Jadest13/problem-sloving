#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF INT32_MAX

using namespace std;

int V, E;
int a, b, c;
long long Dist[401][401];
long long R = INF;

long long min(long long a, long long b) {
  return (a<b)?a:b;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> V >> E;

  for(int i = 1; i <= V; i++) {
    for(int j = 1; j <= V; j++) {
      Dist[i][j] = INF;
    }
  }

  for(int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    Dist[a][b] = c;
  }

  for(int k = 1; k <= V; k++) {
    for(int i = 1; i <= V; i++) {
      for(int j = 1; j <= V; j++) {
        Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
      }
    }
  }

  for(int i = 1; i <= V; i++) {
    R = min(R, Dist[i][i]);
  }

  cout << ((R==INF)?-1:R);

  return 0;
}