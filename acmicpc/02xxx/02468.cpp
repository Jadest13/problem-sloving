#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 101
using namespace std;

int N;
int A[MAX][MAX];
int visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int R = 1;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[i][j];
    }
  }

  for(int i = 1; i < 100; i++) {
    int tmp = 0;
    for(int j = 1; j <= N; j++) {
      for(int k = 1; k <= N; k++) {
        visit[j][k] = 0;
        if(A[j][k] <= i) {
          visit[j][k] = 1;
        }
      }
    }

    for(int j = 1; j <= N; j++) {
      for(int k = 1; k <= N; k++) {
        if(visit[j][k]) continue;
        
        queue<pair<int, int>> Q;
        visit[j][k] = 1;
        Q.push({k, j});

        while(!Q.empty()) {
          int px = Q.front().first;
          int py = Q.front().second;
          Q.pop();

          for(int d = 0; d < 4; d++) {
            int nx = px + dx[d];
            int ny = py + dy[d];

            if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if(visit[ny][nx]) continue;

            visit[ny][nx] = 1;
            Q.push({nx, ny});
          }
        }
        tmp++;
      }
    }

    R = max(R, tmp);
  }

  cout << R;

  return 0;
}