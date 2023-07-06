#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, str);
  for(auto a : str) {
    if('a' <= a && a <= 'z') {
      cout << (char)((a-'a'+13)%26 + 'a');
    } else if('A' <= a && a <= 'Z') {
      cout << (char)((a-'A'+13)%26 + 'A');
    } else cout << a;
  }

  return 0;
}