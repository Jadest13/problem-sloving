#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int D, H, W;
double a;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> D >> H >> W;
  a = sqrt(1.0*pow(D, 2)/(pow(H, 2) + pow(W, 2)));
  cout << (int)(H*a) << " " << (int)(W*a);

  return 0;
}