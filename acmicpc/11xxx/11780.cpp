#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, m;
int a, b, c;
int D[101][101];
int R[101][101];
vector<int> V;

void find(int s, int e) {
  if(!R[s][e]) {
    V.push_back(s);
    V.push_back(e);
    return;
  }

  find(s, R[s][e]);
  V.pop_back();
  find(R[s][e], e);
}

void F() {

  for(int k = 1; k <= n; k++) {
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        if(i==j) continue;
        if(D[i][k] + D[k][j] < D[i][j]) {
          D[i][j] = D[i][k] + D[k][j];
          R[i][j] = k;
        }
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      D[i][j] = INF;
    }
  }

  for(int i = 1; i <= m; i++) {
    cin >> a >> b >> c;
    D[a][b] = min(D[a][b], c);
  }

  F();

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(D[i][j] == INF) {
        cout << 0 << " ";
      } else {
        cout << D[i][j] << " ";
      }
    }
    cout << "\n";
  }

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if(D[i][j] == INF) {
        cout << 0;
      } else {
        V.clear();
        find(i, j);
        cout << V.size();
        for(int k = 0; k < V.size(); k++) {
          cout << " " << V[k];
        }
      }
      cout << "\n";
    }
  }

  return 0;
}