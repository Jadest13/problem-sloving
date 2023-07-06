#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define MAX INT32_MAX

int N, M;
int A[11][11];
int V[12][12];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int idx;
vector<pair<int, pair<int, int>>> E;
int P[7];
int R;

int find_node(int x) {
  if(x == P[x]) return x;
  else return P[x] = find_node(P[x]);
}

void union_node(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) P[v] = u;
}

void F(int x, int y) {
  queue<pair<int, int>> Q; 
  idx++;

  V[x][y] = idx;
  Q.push({x, y});

  while(!Q.empty()) {
    int px = Q.front().first;
    int py = Q.front().second;
    Q.pop();

    for(int i = 0; i < 4; i++) {
      int nx = px + dx[i];
      int ny = py + dy[i];

      if(A[nx][ny] && !V[nx][ny]) {
        V[nx][ny] = idx;
        Q.push({nx, ny});
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= 6; i++) {
    P[i] = i;
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[j][i];
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(A[j][i] && !V[j][i]) {
        F(j, i);
      }
    }
  }
  /* 
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cout << V[j][i];
    }
    cout << "\n";
  }
 */
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      if(V[j][i]) {
        for(int k = 0; k < 4; k++) {
          int nx = j;
          int ny = i;
          int d = 0;

          while(1) {
            nx += dx[k];
            ny += dy[k];
            if(V[nx][ny]) break;
            if(nx < 1 || ny < 1 || nx > M || ny > N) break;
            d++;
          }

          if(!V[nx][ny]) continue;

          if(d <= 1) continue;

          if(V[j][i] == V[nx][ny]) continue;

          //printf("%d,%d/%d,%d %d\n", j, i, nx, ny, d);
          E.push_back({d, {V[j][i], V[nx][ny]}});
        }
      }
    }
  }

  sort(E.begin(), E.end());

  for(auto a : E) {
    int u = find_node(a.second.first);
    int v = find_node(a.second.second);

    if(u==v) continue;

    //cout << u << " " << v << " " << a.first << "\n";
    union_node(u, v);
    R += a.first;
  }

  for(int i = 1; i < idx; i++) {
    if(find_node(i) != find_node(i+1)) {
      R = 0;
      break;
    }
  }

  cout << (R?R:-1);

  return 0;
}