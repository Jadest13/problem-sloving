#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cout << fixed;
  cout.precision(9);
  cout << sqrt(3)/2*N*N/2;

  return 0;
}