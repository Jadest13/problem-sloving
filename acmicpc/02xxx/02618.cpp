#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

#define MAX INT32_MAX

using namespace std;

int N, W;
int x, y;
vector<pair<int, int>> V;
int DP[1001][1001];

int calc(int x1, int y1, int x2, int y2) {
  return abs(x1-x2) + abs(y1-y2);
}

void F2(int P1, int P2, int x1, int y1, int x2, int y2) {

  if(P1 == W || P2 == W) return;

  int next = max(P1, P2)+1;
  int nx = V[next].first;
  int ny = V[next].second;

  if(DP[next][P2] + calc(x1, y1, nx, ny) < DP[P1][next] + calc(x2, y2, nx, ny)) {
    cout << 1 << "\n";
    F2(next, P2, nx, ny, x2, y2);
  } else {
    cout << 2 << "\n";
    F2(P1, next, x1, y1, nx, ny);
  }
}

int F1(int P1, int P2, int x1, int y1, int x2, int y2) {
  
  if(P1 == W || P2 == W) return 0;
  if(DP[P1][P2] != -1) return DP[P1][P2];

  int next = max(P1, P2)+1;
  int nx = V[next].first;
  int ny = V[next].second;

  return DP[P1][P2] = min(F1(next, P2, nx, ny, x2, y2) + calc(x1, y1, nx, ny), F1(P1, next, x1, y1, nx, ny) + calc(x2, y2, nx, ny));
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(DP, -1, sizeof(DP));

  cin >> N >> W;
  V.push_back({0, 0});
  for(int i = 0; i < W; i++) {
    cin >> x >> y;
    V.push_back({x, y});
  }

  cout << F1(0, 0, 1, 1, N, N) << "\n";
  F2(0, 0, 1, 1, N, N);
  
  return 0;
}