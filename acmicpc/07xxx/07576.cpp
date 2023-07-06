#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int M, N;
int A[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int V[1001][1001];
queue<pair<int, int>> Q;
int ret;

void F() {
  while(!Q.empty()) {
    int px = Q.front().first;
    int py = Q.front().second;
    Q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];

      if(nx <= 0 || ny <= 0 || nx > M || ny > N) {
        continue;
      }

      if(A[nx][ny] == 0) {
        A[nx][ny] = A[px][py] + 1;
        ret = max(ret, A[nx][ny]);
        Q.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  memset(V, -1, sizeof(V));
  
  cin >> M >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[j][i];
      if(A[j][i] == 1) {
        Q.push(make_pair(j, i));
      }
    }
  }
  
  ret = 1;
  F();

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(A[j][i] == 0) {
        ret = 0;
        break;
      }
    }
    if(ret == 0) {
      break;
    }
  }

  cout << ret - 1;

  return 0;
}