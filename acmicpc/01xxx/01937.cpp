#include <bits/stdc++.h>

#define MAX 501

using namespace std;

int N;
int A[MAX][MAX];
int Visit[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int R = 0;

int F(int y, int x) {
  if(Visit[y][x]) return Visit[y][x];
  
  for(int d = 0; d < 4; d++) {
    int py = y + dy[d];
    int px = x + dx[d];

    if(py < 1 || py > N || px < 1 || px > N) continue;
    if(A[y][x] <= A[py][px]) continue;
    Visit[y][x] = max(Visit[y][x], F(py, px)+1);
  }
  return Visit[y][x];
}

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

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(Visit[i][j]) continue;
      R = max(R, F(i, j));
    }
  }

  cout << R+1;

  return 0;
}