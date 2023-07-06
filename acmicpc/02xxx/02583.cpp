#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 101

using namespace std;

int M, N, K;
int A[MAX][MAX];
int x1, y1, x2, y2;
int visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<int> R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M >> N >> K;
  for(int i = 1; i <= K; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    for(int j = x1+1; j <= x2; j++) {
      for(int k = y1+1; k <= y2; k++) {
        visit[j][k]++;
      }
    }
  }
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(visit[i][j]) continue;

      queue<pair<int, int>> Q;
      int w = 0;
      visit[i][j] = 1;
      Q.push({i, j});
      while(!Q.empty()) {
        w++;
        int px = Q.front().first;
        int py = Q.front().second;
        Q.pop();

        for(int d = 0; d < 4; d++) {
          int nx = px + dx[d];
          int ny = py + dy[d];

          if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
          if(visit[nx][ny]) continue;

          visit[nx][ny] = 1;
          Q.push({nx, ny});
        }
      }
      R.push_back(w);
    }
  }

  sort(R.begin(), R.end());
  cout << R.size() << "\n";
  for(auto a : R) {
    cout << a << " ";
  }

  return 0;
}