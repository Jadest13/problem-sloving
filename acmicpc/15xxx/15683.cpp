#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 8+1

using namespace std;
typedef struct {
  int a, x, y;
} CCTV;

int N, M;
int A[MAX][MAX];
int visit[MAX][MAX];
vector<CCTV> V;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void L(int x, int y, int d, int a) {
  int px = x + dx[d];
  int py = y + dy[d];

  while(py >= 1 && py <= N && px >= 1 && px <= M && A[py][px] != 6) {
    visit[py][px] += a;
    px += dx[d];
    py += dy[d];
  }
}

int F(int n) {
  int ret = (MAX)*(MAX);
  if(n == V.size()) {
    ret = 0;
    for(int i = 1; i <= N; i++) {
      for(int j = 1; j <= M; j++) {
        if(visit[i][j] == 0) ret++;
      }
    }
    return ret;
  }
  if(V[n].a == 5) {
    for(int i = 0; i < 4; i++)
      L(V[n].x, V[n].y, i, 1);
    ret = min(ret, F(n+1));
    for(int i = 0; i < 4; i++)
      L(V[n].x, V[n].y, i, -1);
  } else if(V[n].a == 4) {
    for(int i = 0; i < 4; i++)
      L(V[n].x, V[n].y, i, 1);

    for(int i = 0; i < 4; i++) {
      L(V[n].x, V[n].y, i, -1);
      ret = min(ret, F(n+1));
      L(V[n].x, V[n].y, i, 1);
    }

    for(int i = 0; i < 4; i++)
      L(V[n].x, V[n].y, i, -1);
  } else if(V[n].a == 3) {
    for(int i = 0; i < 4; i++) {
      L(V[n].x, V[n].y, i, 1);
      L(V[n].x, V[n].y, (i+1)%4, 1);
      ret = min(ret, F(n+1));
      L(V[n].x, V[n].y, i, -1);
      L(V[n].x, V[n].y, (i+1)%4, -1);
    }
  } else if(V[n].a == 2) {
    for(int i = 0; i < 2; i++) {
      L(V[n].x, V[n].y, i, 1);
      L(V[n].x, V[n].y, i+2, 1);
      ret = min(ret, F(n+1));
      L(V[n].x, V[n].y, i, -1);
      L(V[n].x, V[n].y, i+2, -1);
    }
  } else if(V[n].a == 1) {
    for(int i = 0; i < 4; i++) {
      L(V[n].x, V[n].y, i, 1);
      ret = min(ret, F(n+1));
      L(V[n].x, V[n].y, i, -1);
    }
  }
  return ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> A[i][j];
      if(A[i][j] > 0 && A[i][j] < 6) V.push_back({A[i][j], j, i});
      if(A[i][j]) visit[i][j] = 1;
    }
  }
  sort(V.begin(), V.end(), [](CCTV a, CCTV b) {
    if(a.a == b.a) {
      if(a.x == b.x) return a.y < b.y;
      else return a.x < b.x;
    } else return a.a > b.a;
  });

  cout << F(0);

  return 0;
}