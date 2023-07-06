#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  double x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  double d = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));

  double R = 0;
  if(r1+r2 <= d) {
    R = 0;
  } else if(abs(r2-r1) >= d) {
    R = M_PI * pow(min(r1, r2), 2);
  } else {
    double O1 = acos((pow(r1,2) + pow(d, 2) - pow(r2, 2)) / (2 * r1 * d));
    double O2 = acos((pow(r2,2) + pow(d, 2) - pow(r1, 2)) / (2 * r2 * d));
    double S1 = pow(r1, 2)*(O1 - sin(2*O1)/2);
    double S2 = pow(r2, 2)*(O2 - sin(2*O2)/2);
    R = S1 + S2;
  }

  cout << fixed;
  cout.precision(3);
  cout << R;

  return 0;
}