#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
string S;
int A[101][101], V[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int F(int x, int y) {
  V[x][y] = 1;
  queue<pair<int, int>> Q;
  Q.push(make_pair(x, y));

  while(!Q.empty()) {
    int px = Q.front().first;
    int py = Q.front().second;

    Q.pop();
    

    if(px == N && py == M) {
      break;
    }

    for(int i = 0; i < 4; i++) {
      int nx = px+dx[i];
      int ny = py+dy[i];

      if(nx > 0 && ny > 0 && nx <= N && ny <= M && A[nx][ny] && !V[nx][ny]) {
        V[nx][ny] = 1;
        Q.push(make_pair(nx, ny));
        A[nx][ny] = A[px][py] + 1;
      }
    }
  }

  return A[N][M];
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= M; j++) {
      A[i][j] = S[j-1] - '0';
    }
  }
  cout << F(1, 1);

  return 0;
}