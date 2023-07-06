#include <iostream>
#include <algorithm>
#include <queue>

#define MAX 501

using namespace std;
using PII = pair<int, int>;

int N, M;
int A[MAX][MAX];
int visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int R;
int mx;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(!A[i][j] || visit[i][j]) continue;

      int tmp = 0;
      queue<PII> Q;
      visit[i][j] = 1;
      Q.push({i, j});
      while(!Q.empty()) {
        tmp++;
        int py = Q.front().first;
        int px = Q.front().second;
        Q.pop();

        for(int d = 0; d < 4; d++) {
          int ny = py + dy[d];
          int nx = px + dx[d];

          if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
          if(!A[ny][nx] || visit[ny][nx]) continue;

          visit[ny][nx] = 1;
          Q.push({ny, nx});
        }
      }
      R++;
      mx = max(mx, tmp);
    }
  }

  cout << R << "\n" << mx;

  return 0;
}