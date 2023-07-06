#include <iostream>

using namespace std;

int T, a, b, r;

int main() {

  cin >> T;
  for(int i = 0; i < T; i++) {
    cin >> a >> b;
    a %= 10;
    r = 1;
    for(int j = 0; j < b; j++) {
      r *= a;
      r %= 10;
    }

    cout << (r==0?10:r) << endl;
  }
  
  return 0;
}