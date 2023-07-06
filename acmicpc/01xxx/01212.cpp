#include <iostream>
#include <algorithm>

using namespace std;

string str;
int flag;
string R;

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;
  if(str == "0") cout << 0;
  else {
    for(auto a : str) {
      int d = a-'0';
      R.push_back(d/4 + '0');
      R.push_back((d%4)/2 + '0');
      R.push_back((d%4)%2 + '0');
    }
    for(auto a : R) {
      if(!flag && a == '0') continue;
      flag = 1;
      cout << a;
    }
  }

  return 0;
}