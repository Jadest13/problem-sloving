#include <iostream>
#include <algorithm>

using namespace std;

string str;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  cout << fixed;
  cout.precision(1);
  if(str == "F") cout << 0.0;
  else cout << (4 - (str[0]-'A')) + (str[1]=='+'?0.3:(str[1]=='-'?-0.3:0));

  return 0;
}