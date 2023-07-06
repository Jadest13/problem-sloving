#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF INT32_MAX

using namespace std;

int n, m;
int a, b, c;
long long Dist[101][101], Cost[101][101];

long long min(long long a, long long b) {
  return (a<b)?a:b;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= n; j++) {
      Cost[i][j] = INF;
    }
  }

  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    Cost[a][b] = min(Cost[a][b], c);
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(i==j) Dist[i][j] = 0;
      else if (Cost[i][j] != INF) Dist[i][j] = Cost[i][j];
      else Dist[i][j] = INF;
    }
  }

  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        Dist[i][j] = min(Dist[i][j], Dist[i][k] + Dist[k][j]);
      }
    }
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(Dist[i][j] == INF) cout << 0 << " ";
      else cout << Dist[i][j] << " ";
    }
    cout << "\n";
  }


  return 0;
}