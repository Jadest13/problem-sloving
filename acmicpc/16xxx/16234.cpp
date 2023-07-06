#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N, L, R;
int A[51][51];
int V[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int res;

void F(int r, int x, int y) {
  queue<pair<int, int>> Q;
  int sum = A[x][y];
  int n = 1;
  Q.push({x, y});
  V[x][y] = r;

  while(!Q.empty()) {
    int px = Q.front().first;
    int py = Q.front().second;
    Q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];

      if(nx < 1 || ny < 1 || nx > N || ny > N) {
        continue;
      }

      if(V[nx][ny]) {
        continue;
      }

      if(abs(A[nx][ny] - A[px][py]) >= L && abs(A[nx][ny] - A[px][py]) <= R) {
        V[nx][ny] = r;
        sum += A[nx][ny];
        n++;
        Q.push({nx, ny});
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(V[j][i] == r) {
        A[j][i] = sum / n;
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> L >> R;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[j][i];
    }
  }

  while(1) {
    memset(V, 0, sizeof(V));
    int r = 0;

    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        if(V[j][i]) continue;

        for(int k = 0; k < 4; k++) {
          int nx = j + dx[k];
          int ny = i + dy[k];

          if(nx < 1 || ny < 1 || nx > N || ny > N) {
            continue;
          }

          if(abs(A[nx][ny] - A[j][i]) >= L && abs(A[nx][ny] - A[j][i]) <= R) {
            F(++r, j, i);
            break;
          }
        }
      }
    }

    if(!r) break;
    res++;
  }

  cout << res;

  return 0;
}