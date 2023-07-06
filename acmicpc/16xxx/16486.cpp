#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double d1, d2;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> d1 >> d2;
  cout << fixed;
  cout.precision(6);
  cout << 2*d1 + 2*M_PI*d2;

  return 0;
}