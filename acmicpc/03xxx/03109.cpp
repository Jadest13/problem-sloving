#include <iostream>
#include <algorithm>

using namespace std;

int R, C;
string S;
int ARR[10001][501];
int visit[10001][501];
int res;

int DFS(int r, int c) {
  int ret = 0;
  visit[r][c] = 1;
  if(c == C) {
    return 1;
  }
  for(int i = -1; i <= 1; i++) {
    if(r+i >= 1 && r+i <= R && !ARR[r+i][c+1] && !visit[r+i][c+1]) {
      ret = DFS(r+i, c+1);
      if(ret) break;
    }
  }
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;
  for(int i = 1; i <= R; i++) {
    cin >> S;
    for(int j = 1; j <= C; j++) {
      ARR[i][j] = (S[j-1]=='.')?0:1;
    }
  }
  for(int i = 1; i <= R; i++) {
    res += DFS(i, 1);
  }

  cout << res;

  return 0;
}