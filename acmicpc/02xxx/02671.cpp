#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;

string S;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  regex re("(100+1+|01)+");

  cin >> S;
  cout << (regex_match(S, re)?"SUBMARINE\n":"NOISE\n");

  return 0;
}