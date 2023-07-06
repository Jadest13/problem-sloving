#include <bits/stdc++.h>

#define MAX 21

using namespace std;

int R, C;
string str;
int A[MAX][MAX];
int Alpha[26];
int Visit[MAX][MAX];
int ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int DFS(int y, int x) {
  Visit[y][x] = 1;
  Alpha[A[y][x]] = 1;

  int ret = 1;

  for(int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx < 1 || ny < 1 || nx > C || ny > R) continue;
    if(Alpha[A[ny][nx]]) continue;
    if(Visit[ny][nx]) continue;

    ret = max(ret, DFS(ny, nx)+1);
  }

  Visit[y][x] = 0;
  Alpha[A[y][x]] = 0; 

  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;
  for(int i = 1; i <= R; i++) {
    cin >> str;
    for(int j = 1; j <= C; j++) {
      A[i][j] = str[j-1]-'A';
    }
  }

  cout << DFS(1, 1);

  return 0;
}