#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int T, I;
int sx, sy, ex, ey;
int dx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dy[] = {2, 2, 1, -1, -2, -2, -1, 1};
int V[302][302];

void F() {
  queue<pair<int, int>> Q;
  V[sx][sy] = 0;
  Q.push(make_pair(sx, sy));

  while(!Q.empty()) {
    int px = Q.front().first;
    int py = Q.front().second;
    Q.pop();

    if(px == ex && py == ey) {
      break;
    }

    for(int i = 0; i < 8; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];

      if(nx < 0 || ny < 0 || nx >= I || ny >= I) {
        continue;
      }

      if(V[nx][ny] > V[px][py]+1) {
        V[nx][ny] = V[px][py] + 1;
        Q.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    for(int i = 0; i < 300; i++) {
      for(int j = 0; j < 300; j++) {
        V[i][j] = 1e9;
      }
    }

    cin >> I;
    cin >> sx >> sy >> ex >> ey;
    F();
    cout << V[ex][ey] << "\n";
  }

  return 0;
}