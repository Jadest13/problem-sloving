#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
clock_t stt, edt;

#define max(a, b) a>b?a:b
#define MAX 50+1

using namespace std;

typedef struct {
  int x, y;
  int xy;
} Point;

int N, M;
string str;
int A[1 << 12];
vector<Point> R, G, B;
int W[2501][2501];
int res;

int ccw(Point a, Point b, Point c) {
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> str;
    for(int j = 0; j < M; j++) {
      switch (str[j]) {
        case 'R':
          A[(i<<6)+j] = 2; break;
        case 'G':
          A[(i<<6)+j] = 3; break;
        case 'B':
          A[(i<<6)+j] = 5; break;
      }
      for(int u = 0; u < (i<<6)+j; u++) {
        for(int v = u+1; v < (i<<6)+j; v++) {
          =
        }
      }
    }
  }

  stt = clock();
  int w;
  int i, j, k;
  for(auto r : R) {
    i = r.xy;
    for(auto g : G) {
      j = g.xy;
      for(auto b : B) {
        k = b.xy;
        w = abs(ccw(r, g, b));
        if(!w) continue;
        W[i][j] = max(W[i][j], w);
        W[i][k] = max(W[i][k], w);
        W[j][k] = max(W[j][k], w);
      }
    }
  }
  
  for(auto r : R) {
    i = r.xy;
    for(auto g : G) {
      j = g.xy;
      for(auto b : B) {
        k = b.xy;
        w = abs(ccw(r, g, b));
        if(W[i][j] > w || W[i][k] > w || W[j][k] > w)
          res++;
      }
    }
  }

  cout << res;

  edt = clock();

  cout << (double)(edt - stt) / CLOCKS_PER_SEC << "ÃÊ" << endl;

  return 0;
}