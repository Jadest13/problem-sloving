#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N;
string S;
char A[101][101];
bool V[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void F2(int x, int y, bool b) {
  char C = A[x][y];
  queue<pair<int, int>> Q;
  Q.push({x, y});
  V[x][y] = 1;

  while(!Q.empty()) {
    int px = Q.front().first;
    int py = Q.front().second;
    Q.pop();
    
    for(int i = 0; i < 4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];

      if(nx < 1 || ny < 1 || nx > N || ny > N) {
        continue;
      }

      if(!V[nx][ny]) {
        if(b && (C == 'R' || C == 'G') && (A[nx][ny] == 'R' || A[nx][ny] == 'G')) {
          V[nx][ny] = true;
          Q.push({nx, ny});
        } else if(C == A[nx][ny]) {
          V[nx][ny] = true;
          Q.push({nx, ny});
        }
      }
    }
  }
}

int F1(bool b) {
  memset(V, false, sizeof(V));

  int R = 0;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      if(!V[j][i]) {
        F2(j, i, b);
        R++;
      }
    }
  }

  return R;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> S;
    for(int j = 1; j <= N; j++) {
      A[j][i] = S[j-1];
    }
  }

  cout << F1(false) << " " << F1(true);

  return 0;
}