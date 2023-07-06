#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 125+1
#define INF 1e9

using namespace std;
using PII = pair<int, int>;
using PIPII = pair<int, PII>;

int N;
int A[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int D[MAX][MAX];

int F() {
  priority_queue<PIPII, vector<PIPII>, greater<PIPII>> PQ;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      D[i][j] = INF;
    }
  }

  D[1][1] = A[1][1];
  PQ.push({D[1][1], {1, 1}});

  while(!PQ.empty()) {
    int pd = PQ.top().first;
    int px = PQ.top().second.first;
    int py = PQ.top().second.second;
    PQ.pop();

    for(int i = 0; i < 4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];

      if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
      if(D[px][py] + A[nx][ny] < D[nx][ny]) {
        D[nx][ny] = D[px][py] + A[nx][ny];
        PQ.push({D[nx][ny], {nx, ny}});
      }
    }
  }

  return D[N][N];
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T = 0;
  while(++T) {
    cin >> N;
    if(!N) break;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= N; j++) {
        cin >> A[i][j];
      }
    }

    cout << "Problem " << T << ": " << F() << "\n";
  }

  return 0;
}