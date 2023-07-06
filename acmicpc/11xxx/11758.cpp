#include <iostream>
#include <algorithm>

using namespace std;

int X[3], Y[3];
int R;

int ccw(int x1, int x2, int x3, int y1, int y2, int y3) {
  return (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for(int i = 0; i < 3; i++) {
    cin >> X[i] >> Y[i];
  }
  R = ccw(X[0], X[1], X[2], Y[0], Y[1], Y[2]);
  if(R<0) cout << -1;
  else if(R>0) cout << 1;
  else cout << 0;

  return 0;
}