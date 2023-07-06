#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

int T;
string S;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  regex re("(100+1+|01)+");

  cin >> T;
  while(T--) {
    cin >> S;
    cout << (regex_match(S, re)?"YES\n":"NO\n");
  }

  return 0;
}