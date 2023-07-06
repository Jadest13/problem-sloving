#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int x1, y1, x2, y2, x3, y3;
double l1, l2, l3;
double R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  l1 = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
  l2 = sqrt(pow(x3-x1, 2) + pow(y3-y1, 2));
  l3 = sqrt(pow(x3-x2, 2) + pow(y3-y2, 2));
  R = l1*2 + l2*2 + l3*2;
  cout << R*2 - min(l1, l2, l3) - max(l1, l2, l3);

  return 0;
}