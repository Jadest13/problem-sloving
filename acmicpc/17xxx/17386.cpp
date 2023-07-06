#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef struct {
  LL x;
  LL y;
} Point;

Point P1, P2, P3, P4;

int ccw(Point p1, Point p2, Point p3) {
  LL tmp = (p1.x * p2.y) + (p2.x * p3.y) + (p3.x * p1.y);
  tmp -= (p1.x * p3.y) + (p2.x * p1.y) + (p3.x * p2.y);

  if(tmp > 0) return 1;
  else if(tmp < 0) return -1;
  else return 0;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> P1.x >> P1.y >> P2.x >> P2.y;
  cin >> P3.x >> P3.y >> P4.x >> P4.y;

  int A = ccw(P1, P2, P3) * ccw(P1, P2, P4);
  int B = ccw(P3, P4, P1) * ccw(P3, P4, P2);

  if(A < 0 && B < 0) {
    cout << "1";
  } else {
    cout << "0";
  }

  return 0;
}