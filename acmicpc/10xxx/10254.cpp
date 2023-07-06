#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using LL = long long;

typedef struct {
  LL x, y;
} Point;

int T;
int N;
Point P[200001];
vector<Point> V;
LL R;
Point R1, R2;

LL dist(Point a, Point b) {
  return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

LL ccw(Point a, Point b, Point c) {
  return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}

LL rc(Point a, Point b, Point c, Point d) {
  return ccw(a, b, {d.x + b.x - c.x, d.y + b.y - c.y});
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    V.clear();
    cin >> N;

    for(int i = 1; i <= N; i++) {
      cin >> P[i].x >> P[i].y;
    }
    sort(P+1, P+N+1, [](Point a, Point b) {
      if(a.y == b.y) return a.x < b.x;
      else return a.y < b.y;
    });
    sort(P+1+1, P+N+1, [](Point a, Point b) {
      if(ccw(P[1], a, b) == 0) {
        return dist(P[1], a) < dist(P[1], b);
      }
      return ccw(P[1], a, b) > 0;
    });

    V.push_back(P[1]);
    V.push_back(P[2]);
    for(int i = 3; i <= N; i++) {
      while(V.size() >= 2 && ccw(V[V.size()-2], V[V.size()-1], P[i]) <= 0) {
        V.pop_back();
      }
      V.push_back(P[i]);
    }

    R = 0;
    int c = 1, sz = V.size();
    for(int i = 0; i < sz; i++) {
      while((c+1)%sz != i && rc(V[i], V[(i+1)%sz], V[c], V[(c+1)%sz]) > 0) {
        if(R < dist(V[i], V[c])) {
          R = dist(V[i], V[c]);
          R1 = V[i];
          R2 = V[c];
        }
        c++;
        c %= sz;
      }
      
      if(R < dist(V[i], V[c])) {
        R = dist(V[i], V[c]);
        R1 = V[i];
        R2 = V[c];
      }
    }

    cout << R1.x << " " << R1.y << " " << R2.x << " " << R2.y << "\n";
  }

  return 0;
}