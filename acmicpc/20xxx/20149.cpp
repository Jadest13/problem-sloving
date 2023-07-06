#include <iostream>
#include <algorithm>

#define x first;
#define y second;

using namespace std;

typedef long long LL;
pair<LL, LL> P[5];

int ccw(pair<LL, LL> p1, pair<LL, LL> p2, pair<LL, LL> p3) {
  LL tmp = (p1.first * p2.second) + (p2.first * p3.second) + (p3.first * p1.second);
  tmp -= (p1.first * p3.second) + (p2.first * p1.second) + (p3.first * p2.second);

  if(tmp > 0) return 1;
  else if(tmp < 0) return -1;
  else return 0;
}

void get_point(pair<LL, LL> P1, pair<LL, LL> P2, pair<LL, LL> P3, pair<LL, LL> P4) {
  double px = (P1.first*P2.second-P2.first*P1.second)*(P3.first-P4.first) - (P3.first*P4.second-P4.first*P3.second)*(P1.first-P2.first);
  double py = (P1.first*P2.second-P2.first*P1.second)*(P3.second-P4.second) - (P3.first*P4.second-P4.first*P3.second)*(P1.second-P2.second);
  double p = (P1.first-P2.first)*(P3.second-P4.second) - (P1.second-P2.second)*(P3.first-P4.first);

  cout.precision(17);
  if(p == 0) {
    if(P2 == P3 && P1 <= P3) cout << P2.first << " " << P2.second;
    else if(P1 == P4 && P1 >= P3) cout << P1.first << " " << P1.second;
  } else {
    cout << px/p << " " << py/p;
  }
}

void result() {

  int A = ccw(P[1], P[2], P[3]) * ccw(P[1], P[2], P[4]);
  int B = ccw(P[3], P[4], P[1]) * ccw(P[3], P[4], P[2]);

  if(!A && !B) {
    if(P[1] > P[2]) swap(P[1], P[2]);
    if(P[3] > P[4]) swap(P[3], P[4]);
    if(P[1] <= P[4] && P[2] >= P[3]) {
      cout << "1\n";
      get_point(P[1], P[2], P[3], P[4]);
    }
    else cout << "0\n";
  } else if(A <= 0 && B <= 0) {
    cout << "1\n";
    get_point(P[1], P[2], P[3], P[4]);
  } else {
    cout << "0\n";
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 1; i <= 4; i++) {
    int a, b;
    cin >> a >> b;
    P[i] = {a, b};
  }

  result();

  return 0;
}