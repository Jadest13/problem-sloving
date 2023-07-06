#include <iostream>
#include <algorithm>

using namespace std;

int T;
int C;
int a, b, c, d;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    cin >> C;
    a = C / 25;
    C %= 25;
    b = C / 10;
    C %= 10;
    c = C / 5;
    C %= 5;
    d = C;
    cout << a << " " << b << " " << c << " " << d << "\n";
  }

  return 0;
}