#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int x, y;
int A[101][101];
int L;
int X;
char C;
int d;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> S;
queue<pair<int, char>> D;
int T;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  for(int i = 0; i < K; i++) {
    cin >> y >> x;
    A[x][y] = 1;
  }
  cin >> L;
  for(int i = 0; i < L; i++) {
    cin >> X >> C;
    D.push({X, C});
  }

  S.push({1,1});
  A[1][1] = -1;

  while(1) {
    T++;
    int nx = S.back().first + dx[d];
    int ny = S.back().second + dy[d];

    if(nx < 1 || ny < 1 || nx > N || ny > N || A[nx][ny] == -1) {
      break;
    }

    S.push({nx, ny});
    if(!A[nx][ny]) {
      A[S.front().first][S.front().second] = 0;
      S.pop();
    }
    A[nx][ny] = -1;
    
    if(T == D.front().first) {
      if(D.front().second == 'L') {
        d = (d+3)%4;
      } else {
        d = (d+1)%4;
      }
      D.pop();
    }
  }

  cout << T;

  return 0;
}