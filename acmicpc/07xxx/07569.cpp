#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int M, N, H;
int A[101][101][101];
int dx[] = {1, 0, 0, -1, 0, 0};
int dy[] = {0, 1, 0, 0, -1, 0};
int dz[] = {0, 0, 1, 0, 0, -1};
queue<tuple<int, int, int>> Q;
int ret;

void F() {
  while(!Q.empty()) {
    int px = get<0>(Q.front());
    int py = get<1>(Q.front());
    int pz = get<2>(Q.front());
    Q.pop();

    for(int i = 0; i < 6; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];
      int nz = pz + dz[i];

      if(nx <= 0 || ny <= 0 || nz <= 0 || nx > M || ny > N || nz > H) {
        continue;
      }

      if(A[nx][ny][nz] == 0) {
        A[nx][ny][nz] = A[px][py][pz] + 1;
        ret = max(ret, A[nx][ny][nz]);
        Q.push(make_tuple(nx, ny, nz));
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> M >> N >> H;
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = 1; k <= M; k++) {
        cin >> A[k][j][i];
        if(A[k][j][i] == 1) {
          Q.push(make_tuple(k, j, i));
        }
      }
    }
  }
  
  ret = 1;
  F();

  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= N; j++) {
      for(int k = 1; k <= M; k++) {
        if(A[k][j][i] == 0) {
          ret = 0;
          break;
        }
      }
      if(!ret) break;
    }
    if(!ret) break;
  }

  cout << ret - 1;

  return 0;
}