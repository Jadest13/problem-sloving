#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

typedef struct {
  int x, y;
} Point;

int T;
Point P[5];

LL len(Point a, Point b) {
  return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    for(int i = 1; i <= 4; i++) {
      cin >> P[i].x >> P[i].y;
    }
    sort(P+1, P+4+1, [](Point a, Point b) {
      if(a.x == b.x) return a.y < b.y;
      else return a.x < b.x;
    });

    if(len(P[1], P[3]) != len(P[2], P[4])) {
      cout << "0\n";
      continue;
    }

    if(len(P[1], P[2]) != len(P[1], P[3])
    || len(P[1], P[3]) != len(P[2], P[4])
    || len(P[1], P[4]) != len(P[2], P[3])) {
      cout << "0\n";
      continue;
    }

    cout << "1\n";
  }

  return 0;
}