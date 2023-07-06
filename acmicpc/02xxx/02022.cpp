#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double x, y, c;
double l, r;
double k;
double a, b;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x >> y >> c;
  l = 0; r = min(x, y);
  for(int i = 0; i < 1000; i++) {
    k = (r+l)/2.0;
    a = sqrt(pow(x, 2) - pow(k, 2));
    b = sqrt(pow(y, 2) - pow(k, 2));
    
    if(a - a/k*(k/b*c) > c) l = k;
    else r = k;
  }
  cout << fixed;
  cout.precision(3);
  cout << l;

  return 0;
}