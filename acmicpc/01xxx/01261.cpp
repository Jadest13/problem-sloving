#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX INT32_MAX

using namespace std;

int N, M;
string S;
int E[101][101];
int Dist[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int F() {
  priority_queue<pair<int, pair<int, int>>> PQ;
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= M; j++) {
      Dist[i][j] = MAX;
    }
  }

  Dist[1][1] = 0;
  PQ.push({0, {1, 1}});

  while(!PQ.empty()) {
    int now_W = -PQ.top().first;
    int now_x = PQ.top().second.first;
    int now_y = PQ.top().second.second;
    PQ.pop();

    if(now_x == N && now_y == M) {
      break;
    }

    for(int i = 0; i < 4; i++) {
      int next_x = now_x + dx[i];
      int next_y = now_y + dy[i];
      int next_W = now_W;
      if(E[next_x][next_y] == 1) next_W += 1;
      
      if(next_x < 1 || next_y < 1 || next_x > N || next_y > M) {
        continue;
      }

      if(Dist[next_x][next_y] > next_W) {
        Dist[next_x][next_y] = next_W;
        PQ.push({-Dist[next_x][next_y], {next_x, next_y}});
      }
    }
  }
  return Dist[N][M];
}

int main(void) {

  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  for(int i = 1; i <= M; i++) {
    cin >> S;
    for(int j = 1; j <= N; j++) {
      E[j][i] = S[j-1] - '0';
    }
  }

  cout << F();

  exit(0);
}