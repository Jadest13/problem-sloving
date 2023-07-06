#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N, M;
int r, c, d;
int A[51][51];
int V[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int nx, ny;
int R;


int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  cin >> r >> c >> d;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> A[j][i];
    }
  }

  V[c][r] = 1;
  while(1) {
    if(V[c][r] > R) R = V[c][r];

    int clean = 0;
    for(int i = 0; i < 4; i++) {
      d = (d+3)%4;
      nx = c+dx[d];
      ny = r+dy[d];

      if(V[nx][ny] == 0 && A[nx][ny] == 0) {
        V[nx][ny] = R+1;
        c = nx;
        r = ny;
        clean = 1;
        break;
      }
    }
    if(clean) continue;
    nx = c+dx[(d+2)%4];
    ny = r+dy[(d+2)%4];
    if(A[nx][ny] == 1) {
      break;
    }
    c = nx;
    r = ny;
  }

  cout << R;


  
  return 0;
}