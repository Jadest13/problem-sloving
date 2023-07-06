#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int X, Y, D, T;
double dist;
double R = 0;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> X >> Y >> D >> T;
  dist = sqrt(pow(X, 2) + pow(Y, 2));
  if((double)D/T <= 1) {
    R = dist;
  } else {
    R = (int)dist / D * T;
    dist -= (int)dist/D * D;
    if(dist < T) {
      R += dist;
    } else {
      R += T;
    }
  }

  cout << R;

  return 0;
}