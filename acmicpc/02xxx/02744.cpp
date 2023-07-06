#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  for(auto a : str) {
    if(a >= 'a' && a <= 'z') {
      cout << (char)(a + 'A'-'a');
    } else {
      cout << (char)(a + 'a'-'A');
    }
  }

  return 0;
}