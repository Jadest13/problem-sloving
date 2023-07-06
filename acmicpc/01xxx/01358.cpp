#include <iostream>
#include <cmath>

using namespace std;

int W, H, X, Y, P;
int x, y;
int R;

int F(int x, int y) {
  if((x <= X && (pow(x-X, 2) + pow(y-(Y+H/2), 2)) <= pow(H/2, 2))
  || (x >= X+W && (pow(x-(X+W), 2) + pow(y-(Y+H/2), 2)) <= pow(H/2, 2))
  || (x >= X && x <= X+W && y >= Y && y <= Y+H)) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> W >> H >> X >> Y >> P;

  for(int i = 0; i < P; i++) {
    cin >> x >> y;
    R += F(x, y);
  }

  cout << R;

  return 0;
}