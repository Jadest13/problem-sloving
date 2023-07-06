#include <bits/stdc++.h>

#define MAX 51
#define INF 1e9

using namespace std;

using PII = pair<int, int>;
using PIPII = pair<int, PII>;

int N;
string str;
int A[MAX][MAX];
int Visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> str;
    for(int j = 1; j <= N; j++) {
      A[i][j] = str[j-1]-'0';
      Visit[i][j] = INF;
    }
  }

  priority_queue<PIPII, vector<PIPII>, greater<PIPII>> PQ;
  PQ.push({0, {1, 1}});
  Visit[1][1] = 0;
  while(!PQ.empty()) {
    int pc = PQ.top().first;
    int px = PQ.top().second.first;
    int py = PQ.top().second.second;
    PQ.pop();

    if(px == N && py == N) {
      ans = pc;
      break;
    }

    for(int d = 0; d < 4; d++) {
      int nx = px + dx[d];
      int ny = py + dy[d];
      if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
      if(A[ny][nx]) {
        if(Visit[ny][nx] <= pc) continue;
        Visit[ny][nx] = pc;
        PQ.push({pc, {nx, ny}});
      } else {
        if(Visit[ny][nx] <= pc+1) continue;
        Visit[ny][nx] = pc+1;
        PQ.push({pc+1, {nx, ny}});
      }
    }
  }

  cout << ans;

  return 0;
}