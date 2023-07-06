#include <iostream>
#include <algorithm>

using namespace std;

int T;
string str;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while(T--) {
    cin >> str;
    cout << str.front() << str.back() << "\n";
  }

  return 0;
}