#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX INT32_MAX

using namespace std;

int N, M;
int A[51][51];
vector<pair<int, int>> home, chicken;
int res = MAX;
int D[51][51][51][51];

void F(int n, int c, vector<pair<int, int>> V) {

  if(n==M) {
    int ret = 0;
    for(auto a : home) {
      int R = MAX;
      for(auto b : V) {
        R = min(R, D[a.first][a.second][b.first][b.second]);
      }
      ret += R;
    }
    res = min(res, ret);
    return;
  }

  if(c >= chicken.size()) return;

  F(n, c+1, V);
  V.push_back(chicken[c]);
  F(n+1, c+1, V);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[i][j];
      if(A[i][j] == 1) home.push_back({i, j});
      else if(A[i][j] == 2) chicken.push_back({i, j});
    }
  }

  for(auto a : home) {
    for(auto b : chicken) {
      D[a.first][a.second][b.first][b.second] = abs(a.first-b.first) + abs(a.second-b.second);
    }
  }

  vector<pair<int, int>> V;
  F(0, 0, V);

  cout << res;

  return 0;
}