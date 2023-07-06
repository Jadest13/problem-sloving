#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N, W, H;
int A;
double E;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> W >> H;
  E = sqrt(pow(W, 2) + pow(H, 2));
  while(N--) {
    cin >> A;
    if(A <= E) cout << "DA\n";
    else cout << "NE\n";
  }

  return 0;
}