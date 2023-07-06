#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define MAX 100001

using namespace std;
using LL = long long;

typedef struct {
  LL x, y;
} Point;

int N;
Point P[MAX];
vector<Point> V;

LL ccw(Point a, Point b, Point c) {
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

double dist(Point a, Point b) {
  return sqrt(pow((b.x-a.x),2) + pow((b.y-a.y),2));
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> P[i].x >> P[i].y;
  }

  sort(P+1, P+N+1, [](Point a, Point b) {
    if(a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
  });
  
  sort(P+2, P+N+1, [](Point a, Point b) {
    LL c = ccw(P[1], a, b);
    if(c == 0) return dist(P[1], a) < dist(P[1], b);
    else return c > 0;
  });

  for(int i = 1; i <= N; i++) {
    if(i < 3) {
      V.push_back(P[i]);
    } else {
      while(1) {
        LL c = ccw(V[V.size()-2], V[V.size()-1], P[i]);
        if(c > 0) {
          V.push_back(P[i]);
          break;
        } else if(c == 0) {
          V.pop_back();
          V.push_back(P[i]);
          break;
        }
        V.pop_back();
      }
    }
  }

  cout << V.size();

  return 0;
}