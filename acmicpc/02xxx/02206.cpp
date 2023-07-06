#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int N, M;
string S;
int A[1001][1001], V[1001][1001][2];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<tuple<int, int, int>> Q;

int F() {
  Q.push(make_tuple(1, 1, 1));
  V[1][1][1] = 1;
  
  while(!Q.empty()) {
    int px = get<0>(Q.front());
    int py = get<1>(Q.front());
    int B = get<2>(Q.front());
    Q.pop();

    if(px == M && py == N) {
      return V[px][py][B];
    }

    for(int i = 0; i < 4; i++) {
      int nx = px+dx[i];
      int ny = py+dy[i];

      if(nx < 1 || ny < 1 || nx > M || ny > N) {
        continue;
      }

      if(A[nx][ny] && B) {
        V[nx][ny][0] = V[px][py][B] + 1;
        Q.push(make_tuple(nx, ny, 0));
      }

      if(!A[nx][ny] && !V[nx][ny][B]) {
        V[nx][ny][B] = V[px][py][B] + 1;
        Q.push(make_tuple(nx, ny, B));
      }
    }
  }

  return -1;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= M; j++) {
      A[j][i] = S[j-1]-'0';
    }
  }

  cout << F();

  return 0;
}