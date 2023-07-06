#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 20+1

using namespace std;

int N, M, x, y, K;
int A[MAX][MAX];
int d;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
vector<int> dice(7);

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> x >> y >> K;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }
  x++;
  y++;

  for(int i = 1; i <= K; i++) {
    cin >> d;
    int nx = x+dx[d];
    int ny = y+dy[d];
    if(!(nx < 1 || nx > N || ny < 1 || ny > M)) {
      if(d == 1) {
        dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
      } else if(d == 2) {
        dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
      } else if(d == 3) {
        dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
      } else if(d == 4) {
        dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
      }

      if(A[nx][ny] == 0) {
        A[nx][ny] = dice[6];
      } else {
        dice[6] = A[nx][ny];
        A[nx][ny] = 0;
      }

      x = nx;
      y = ny;
      cout << dice[1] << "\n";
    }
  }

  return 0;
}