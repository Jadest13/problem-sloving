#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int N;
int A[21][21];
int V[21][21];
int x, y;
int ss, sf;
int f;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int R;

int F() {
  queue<pair<int, pair<int, int>>> Q;
  memset(V, -1, sizeof(V));
  Q.push({0, {x, y}});
  V[x][y] = 0;
  int rx = 0, ry = 0;
  int r = -1;

  while(!Q.empty()) {
    int pt = Q.front().first;
    int px = Q.front().second.first;
    int py = Q.front().second.second;
    Q.pop();

    if(r > 0 && pt > r) {
      break;
    }

    if(A[px][py] && A[px][py] < ss) {
      if(r == -1) {
        rx = px;
        ry = py;
        r = pt;
      } else if(r == pt) {
        if(py < ry || (py == ry && px < rx)) {
          rx = px;
          ry = py;
        }
      }
    }

    for(int i = 0; i < 4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];
      
      if(nx < 1 || ny < 1 || nx > N || ny > N) {
        continue;
      }

      if(V[nx][ny] == -1 && A[nx][ny] <= ss) {
        V[nx][ny] = pt + 1;
        Q.push({pt+1, {nx, ny}});
      }
    }
  }

  x = rx;
  y = ry;
  A[rx][ry] = 0;

  return r;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> A[j][i];
      if(A[j][i] == 9) {
        x = j;
        y = i;
        A[j][i] = 0;
      } else if(A[j][i]) {
        f++;
      }
    }
  }

  ss = 2;
  while(f) {
    int t = F();
    sf++;
    if(sf == ss) {
      ss++;
      sf = 0;
    }
    
    f--;
    if(t == -1) break;
    R += t;
  }

  cout << R;

  return 0;
}