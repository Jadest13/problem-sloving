#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define INF INT32_MAX

using namespace std;

typedef struct _Point {
  double x;
  double y;
} Point;

int T, N;
Point P[21];
Point V[21][21];
int visit[21];
double R = INF;

Point makeVector(Point a, Point b) {
  return {a.x + b.x, a.y + b.y};
}

double dist(Point p) {
  return sqrt(pow(p.x, 2) + pow(p.y, 2));
}

int F(int idx, Point vector) {
  int a, b;
  for(int i = 1; i <= N; i++) {
    if(visit[i]) continue;
    a = i;
    visit[a] = 1;
    break;
  }

  if(idx == N/2) {
    for(int i = a+1;i <= N; i++) {
      if(visit[i]) continue;
      b = i;
      break;
    }
    R = min(R, min(dist(makeVector(vector, V[a][b])), dist(makeVector(vector, V[b][a]))));
  } else {
    for(int i = a+1;i <= N; i++) {
      if(visit[i]) continue;
      b = i;
      visit[b] = 1;
      F(idx+1, makeVector(vector, V[a][b]));
      F(idx+1, makeVector(vector, V[b][a]));
      visit[b] = 0;
    }
  }
  visit[a] = 0;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    R = INF;
    cin >> N;
    for(int i = 1; i <= N; i++) {
      cin >> P[i].x >> P[i].y;
      if(i > 1) {
        for(int j = 1; j < i; j++) {
          V[j][i] = {P[i].x-P[j].x, P[i].y-P[j].y};
          V[i][j] = {P[j].x-P[i].x, P[j].y-P[i].y};
        }
      }
    }
    F(1, {0, 0});
    cout<<fixed;
    cout.precision(12);
    cout << R << "\n";
  }
}