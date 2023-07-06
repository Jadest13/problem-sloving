#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int r, w, l;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for(int i = 1; ; i++) {
    cin >> r;
    if(!r) break;
    cin >> w >> l;
    cout << "Pizza " << i << " ";
    if(sqrt(pow(w, 2) + pow(l, 2))/2 <= r) {
      cout << "fits";
    } else {
      cout << "does not fit";
    }
    cout << " on the table.\n";
  }

  return 0;
}